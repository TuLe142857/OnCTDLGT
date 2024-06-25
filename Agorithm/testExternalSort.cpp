#include"ExternalSorting.h"


void TestExternalSorting(string sourcefile, string destinationfile, bool need_check = true){
    cout << "External Sorting file \"" << sourcefile << "\" to file \"" << destinationfile << "\"" << endl;
    cout << "MAX MEMORY = " << MAX_MEMORY << endl;
    clock_t start_t, end_t;
    start_t = clock();
    if(!ExternalSorting(sourcefile, destinationfile)){
        cout << "Failed" << endl;
        return;
    }
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t) / (CLOCKS_PER_SEC) << " seconds" << endl;
    if(need_check){
        // cout << "Check sort: ";
        // if(CheckExternalSort(destinationfile))
        //     cout << "true" << endl;
        // else cout << "false" << endl;
        CheckExternalSort(destinationfile);
    }
}

int main(){
    
    bool NeedCreateData = false;
    if(NeedCreateData){
        cout << "Creating data...";
        srand(time(0));
        int data_range_start = 0,
            data_range_end = 100000;
        CreateData("100.txt",   100,        data_range_start, data_range_end);
        CreateData("1k.txt",    1000,       data_range_start, data_range_end);
        CreateData("1tr.txt",   1000000,    data_range_start, data_range_end);
        CreateData("10tr.txt",  10000000,   data_range_start, data_range_end);
        CreateData("100tr.txt", 100000000,  data_range_start, data_range_end);
        cout << "completed!" << endl;
        system("pause");
    }
    


    system("cls");

    // TestExternalSorting("100.txt", "100_out.txt");
    // cout << endl;

    // TestExternalSorting("1k.txt", "1k_out.txt");
    // cout << endl;

    // TestExternalSorting("1tr.txt", "1tr_out.txt");
    // cout << endl;

    // TestExternalSorting("10tr.txt", "10tr_out.txt");
    // cout << endl;

    // TestExternalSorting("100tr.txt", "100tr_out.txt");
    // cout << endl;

    for(int i = 10; i <= 1000000; i *= 10){
        MAX_MEMORY = i;
        TestExternalSorting("10tr.txt", "10tr_out.txt");
        cout << endl;
    }

    TestExternalSorting("100tr.txt", "100tr_out.txt");
    cout << endl;

    return 0;
}