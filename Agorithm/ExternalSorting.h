#pragma once
#include<iostream>
#include<fstream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;

//#define MAX_MEMORY 1000
int MAX_MEMORY = 10000;
//=================== FUNCTION PROTOTYPE


//Tao file chua n du lieu, pham vi gia tri [a, b]
bool CreateData(string file_path, int n, int a, int b);
void QuickSort(int *a, int n);
void _QuickSort(int *a, int low, int high);

bool ExternalSorting(string source_file, string destination_file);
void MergeRun(fstream &f_read1, fstream &f_read2, fstream &f_write1, fstream &f_write2, int &runsize, int &totaldata1, int &totaldata2);
void MergeFile(fstream &file1, fstream &file2, fstream &des_file, int runsize, int totaldata1, int totaldata2);

//Kiem tra file da duoc sort hay chua
bool CheckExternalSort(string filepath);
//======================= FUNCTION DEFINITION

bool ExternalSorting(string source_file, string destination_file){
    const string filepath1 = "subfile1.txt",
                 filepath2 = "subfile2.txt",
                 filepath3 = "subfile3.txt",
                 filepath4 = "subfile4.txt";
    fstream f1(filepath1, ios::in | ios::out | ios::trunc),
            f2(filepath2, ios::in | ios::out | ios::trunc),
            f3(filepath3, ios::in | ios::out | ios::trunc),
            f4(filepath4, ios::in | ios::out | ios::trunc);
    if(!(f1 && f2 && f3 && f4)){
        cout << "Khong mo duoc file phu! " << endl;
        return false;
    }

    fstream input(source_file, ios::in);
    if(!input){
        cout << "Khong mo duoc file input" << endl;
        return false;
    }

    int runsize = MAX_MEMORY;

    int *a = new int[MAX_MEMORY];
    int flag = 1;
    int total_data1 = 0, total_data2 = 0;
    int count = 0;
    int i;

    //cout << "open file ok" << endl;
    //============== QuickSort
    
    while(!input.eof()){
        count = 0;
        while(count < MAX_MEMORY && !input.eof()){
            input >> a[count];
            if(!input.eof())
                count ++;
        }
        QuickSort(a, count);

        /*
        flag = 1 ghi vao file1
        flag = 2 ghi vao file2
        
        */
        if(flag == 1){
            total_data1 += count;
            for( i = 0; i < count; i++)
                f1 << a[i] << " ";
            flag = 2;
        }else{
            total_data2 += count;
            for(i = 0; i < count; i++)
                f2 << a[i] << " ";
            flag = 1;
        }
    }
    delete[]a;
    input.close();
    //reset file
    f1.clear();     f1.seekg(0);
    f2.clear();     f2.seekg(0);

    // cout << "External sort started, total data before sort = " << total_data1 + total_data2 << endl;
    // cout << "td1 = " << total_data1 << endl;
    // cout << "td2 = " << total_data2 << endl;
    // cout << "rs = " << runsize << endl;
    //================ Merge run
    flag = 1;
    /*
    flag = 1: read file(1, 2) write file(3, 4);
    flag = 2: read file(3, 4) write file(1, 2);
    Merge cho den khi ca 2 file(read) co so run == 1(total data <= runsize)
    */

    while(!(total_data1 <= runsize && total_data2 <= runsize)){
        if(flag == 1){
            MergeRun(f1, f2, f3, f4, runsize, total_data1, total_data2);
            flag = 2;
        }
        else{
            MergeRun(f3, f4, f1, f2, runsize, total_data1, total_data2);
            flag = 1;
        }
    }    

    //================ Merge file
    fstream output(destination_file, ios::out);
    if(!output){
        cout << "Khong the mo file output de merge file" << endl;
        return false;
    }
    // cout << "Merge file" << endl;
    // cout << "td1 = " << total_data1 << endl;
    // cout << "td2 = " << total_data2 << endl;
    // cout << "rs = " << runsize << endl;
    if(flag == 1)
        MergeFile(f1, f2, output,  runsize, total_data1, total_data2);
    else    
        MergeFile(f3, f4, output, runsize, total_data1, total_data2);
    
    //================ close, remove file
    output.close();
    f1.close();
    f2.close();
    f3.close();
    f4.close();
    remove(filepath1.c_str());
    remove(filepath2.c_str());
    remove(filepath3.c_str());
    remove(filepath4.c_str());
    return true;
}

void MergeRun(fstream &f_read1, fstream &f_read2, fstream &f_write1, fstream &f_write2, int &runsize, int &totaldata1, int &totaldata2){
    // cout << "MR called" << endl;
    // cout << "\tbefore: " << endl
    //      << "td1 = " << totaldata1 << endl
    //      << "td2 = " << totaldata2 << endl
    //      << "rs = " << runsize << endl;
    int data1, data2;   //du lieu trong f_read1, 2
    int p1 = 0, p2 = 0; //vi tri du lieu (p1 < totaldata1, p2 < totaldata2)
    f_read1 >> data1;
    f_read2 >> data2;

    int countw1 = 0,    //So du lieu ghi trong f_write1
        countw2 = 0;    //So du lieu ghi trong f_write2
    int flag = 1;       //flag = 1 ghi vao f_write1; flag = 2 ghi vao f_write2

    int max1, max2; //maxp1, maxp2 (p1 < max1, p2 < max2)
    while(p1 < totaldata1 && p2 < totaldata2){
        max1 = (p1 + runsize) < totaldata1 ? (p1 + runsize) : totaldata1;
        max2 = (p2 + runsize) < totaldata2 ? (p2 + runsize) : totaldata2;
        if(flag == 1)
        {
            while(p1 < max1 && p2 < max2){
                if(data1 < data2){
                    f_write1 << data1 << " ";
                    countw1 ++;

                    f_read1 >> data1;
                    p1++;
                }else{
                    f_write1 << data2 << " ";
                    countw1 ++;

                    f_read2 >> data2;
                    p2 ++;
                }
            }

            while(p1 < max1){
                f_write1 << data1 << " ";
                countw1 ++;

                f_read1 >> data1;
                p1 ++;
            }

            while(p2 < max2){
                f_write1 << data2 << " ";
                countw1 ++;

                f_read2 >> data2;
                p2 ++;
            }

            flag = 2;
        }//if(flag == 1)

        else
        {   
            while(p1 < max1 && p2 < max2){
                if(data1 < data2){
                    f_write2 << data1 << " ";
                    countw2 ++;

                    f_read1 >> data1;
                    p1 ++;
                }else{
                    f_write2 << data2 << " ";
                    countw2 ++;

                    f_read2 >> data2;
                    p2 ++;
                }
            }

            while(p1 < max1){
                f_write2 << data1 << " ";
                countw2 ++;

                f_read1 >> data1;
                p1 ++;
            }   

            while(p2 < max2){
                f_write2 << data2 << " ";
                countw2 ++;

                f_read2 >> data2;
                p2 ++;
            }

            flag = 1;
        }//else (flag ==2 )
    }

    if(flag == 1)
    {
        while(p1 < totaldata1){
            f_write1 << data1 << " ";
            countw1 ++;

            f_read1 >> data1;
            p1 ++;
        }
        while(p2 < totaldata2){
            f_write1 << data2 << " ";
            countw1 ++;

            f_read2 >> data2;
            p2 ++;
        }
    }//flag == 1
    else 
    {
        while(p1 < totaldata1){
            f_write2 << data1 << " ";
            countw2 ++;

            f_read1 >> data1;
            p1 ++;
        }

        while(p2 < totaldata2){
            f_write2 << data2 << " ";
            countw2 ++;

            f_read2 >> data2;
            p2 ++;
        }
    }//flag == 2

    //reset file
    f_read1.clear();    f_read1.seekg(0);
    f_read2.clear();    f_read2.seekg(0);
    f_write1.clear();   f_write1.seekp(0);
    f_write2.clear();   f_write2.seekp(0);

    //update
    runsize *= 2;
    totaldata1 = countw1;
    totaldata2 = countw2;

    // cout << "\tafter: " << endl
    //      << "td1 = " << totaldata1 << endl
    //      << "td2 = " << totaldata2 << endl
    //      << "rs = " << runsize << endl << endl;
}
void MergeFile(fstream &file1, fstream &file2, fstream &des_file, int runsize, int totaldata1, int totaldata2){
    int data1, data2;
    int p1 = 0, p2 = 0;
    file1 >> data1;
    file2 >> data2;

    int count = 0;

    // cout << "MF called: " << endl   
    //      << "td1 = " << totaldata1 << endl
    //      << "td2 = " << totaldata2 << endl
    //      << "rs = " << runsize << endl 
    //      << "p1 = " << p1 << endl
    //      << "p2 = " << p2 << endl;

    while(p1 < totaldata1 && p2 < totaldata2 ){
        if(count != 0 && count%5 == 0) des_file << endl;
        if(data1 < data2){
            des_file << setw(15) << left << data1;
            file1 >> data1; p1++;
        }
        else{
            des_file << setw(15) << left << data2;
            file2 >> data2; p2++;
        }
        count ++;
    }

    // cout << "afer big while: " << endl
    //      << "p1 = " << p1 << endl
    //      << "p2 = " << p2 << endl;

    while(p1 < totaldata1){
        if(count != 0 && count%5 == 0) des_file << endl;
        des_file << setw(15) << left << data1;
        file1 >> data1; p1++;
        count ++;
    }
    // cout << "p1 = " << p1 << endl;

    while(p2 < totaldata2){
        if(count != 0 && count%5 == 0) des_file << endl;
        des_file << setw(15) << left << data2;
        file2 >> data2; p2++;
        count ++;
    }

    // cout << "p2 = " << p2 << endl;

    // cout << "External Sort completed, total data after sort = " << count << endl;
}

bool CheckExternalSort(string filepath){
    fstream file(filepath);
    if(!file){
        cout << "Khong mo duoc file de kiem tra" << endl;
        return false;
    }
    cout << "Check Sort file \"" << filepath << "\": " << endl;

    int a1 = -1, a2;
    int count = 0;
    while(!file.eof()){
        file >> a2;
        
        if(file.eof()) break;
        if(a1 > a2){
            cout << "\tFile chua duoc sort o vi tri: " << count - 1 << " va " << count << endl
                 << "\ta[" << count-1 << "] = " << a1 << endl
                 << "\ta[" << count << "] = " << a2 << endl
                 << "\tCheck sort: false" << endl;
            return false;
        }
        a1 = a2;
        count ++;
    }

    file.close();
    cout << "\tCheck sort: true" << endl  
         << "\tTotal data = " << count << endl;
    return true;
}

bool CreateData(string file_path, int n, int a, int b){
    fstream file(file_path, ios::out);
    if(!file){
        return false;
    }
    int size = 0;
    int k = b;
    while(k != 0){
        size++;
        k /= 10;
    }
    size += 3;

    for(int i = 1; i <= n; i++){
        k = a + rand()%(b - a + 1);
        file << setw(size) << left << k;
        if(i%5 == 0 && i != n) file << endl;
    }
    file.close();
    return true;
}

void QuickSort(int *a, int n){
    if(n <= 0) return;
    //cout << "Quick sort";
    _QuickSort(a, 0, n-1);
    //cout << " completed " << endl;

}

void _QuickSort(int *a, int low, int high){
    int i = low,
        j = high, 
        pivot = a[(low+high)/2],
        temp;
    while(i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    if(low < j) _QuickSort(a, low, j);
    if(i < high) _QuickSort(a, i, high);
}
