#include"Sort.h"
#include<thread>
#include<conio.h>


int main(){
    system("cls");

    int n;
    cout << "Nhap so luong du lieu muon test: ";
    cin >> n;
    bool need_to_print;
    bool need_to_check;
    int k;
    cout << "In danh sach du lieu: ";
    cin >> k; 
    if(k) need_to_print = true;
    cout << "Check do chinh xac sau khi sort: ";
    cin >> k;
    if(k) need_to_check = true;

    system("cls");
    srand(time(0));
    int *a, *a_copy;
    a = CreateArr(n);
    a_copy = new int[n];

    cout << setw(30) << "" << "SO LUONG DU LIEU: " << n << endl << endl;
    if(need_to_print){
        cout << "Mang truoc khi sap xep: " << endl;
        show_arr(a, n, 20);
        cout << endl;
    }

    clock_t start_t, end_t;

    //============== Quick Sort
    cout << setw(30) << setfill('=') << "" << setfill(' ') << "Quick Sort(de quy)" << endl;
    copy_arr(a, a_copy, n);
    start_t = clock();
    QuickSort(a_copy, n);
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t)/(CLOCKS_PER_SEC) << "s" << endl;
    
    if(need_to_print)
        show_arr(a_copy, n, 20);
    if(need_to_check){
        if(check_sort(a_copy, n))
            cout << "Check: true" << endl;
        else 
            cout << "Check: false" << endl;
    }
    cout << endl;

    //============== Quick Sort
    cout << setw(30) << setfill('=') << "" << setfill(' ') << "Quick Sort(stack)" << endl;
    copy_arr(a, a_copy, n);
    start_t = clock();
    QuickSort_stack(a_copy, n);
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t)/(CLOCKS_PER_SEC) << "s" << endl;
    
    if(need_to_print)
        show_arr(a_copy, n, 20);
    if(need_to_check){
        if(check_sort(a_copy, n))
            cout << "Check: true" << endl;
        else 
            cout << "Check: false" << endl;
    }
    cout << endl;

    //============== Quick Sort
    cout << setw(30) << setfill('=') << "" << setfill(' ') << "Heap Sort" << endl;
    copy_arr(a, a_copy, n);
    start_t = clock();
    HeapSort(a_copy, n);
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t)/(CLOCKS_PER_SEC) << "s" << endl;
    
    if(need_to_print)
        show_arr(a_copy, n, 20);
    if(need_to_check){
        if(check_sort(a_copy, n))
            cout << "Check: true" << endl;
        else 
            cout << "Check: false" << endl;
    }
    cout << endl;

    

    //============== Intersection Sort
    cout << setw(30) << setfill('=') << "" << setfill(' ') << "Intersection Sort" << endl;
    copy_arr(a, a_copy, n);
    start_t = clock();
    IntersectionSort(a_copy, n);
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t)/(CLOCKS_PER_SEC) << "s" << endl;

    if(need_to_print)
        show_arr(a_copy, n, 20);
    if(need_to_check){
        if(check_sort(a_copy, n))
            cout << "Check: true" << endl;
        else 
            cout << "Check: false" << endl;
    }
    cout << endl;

    //============== Selection Sort
    cout << setw(30) << setfill('=') << "" << setfill(' ') << "Selection Sort" << endl;
    copy_arr(a, a_copy, n);
    start_t = clock();
    SelectionSort(a_copy, n);
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t)/(CLOCKS_PER_SEC) << "s" << endl;

    if(need_to_print)
        show_arr(a_copy, n, 20);
    if(need_to_check){
        if(check_sort(a_copy, n))
            cout << "Check: true" << endl;
        else 
            cout << "Check: false" << endl;
    }
    cout << endl;

    //============== Buble Sort
    cout << setw(30) << setfill('=') << "" << setfill(' ') << "Bubble Sort" <<   endl;
    copy_arr(a, a_copy, n);
    start_t = clock();
    BubbleSort(a_copy, n);
    end_t = clock();
    cout << "Time = " << (double(end_t) - start_t)/(CLOCKS_PER_SEC) << "s" << endl;

    if(need_to_print)
        show_arr(a_copy, n, 20);
    if(need_to_check){
        if(check_sort(a_copy, n))
            cout << "Check: true" << endl;
        else 
            cout << "Check: false" << endl;
    }
    cout << endl;
    
    delete [] a;
    delete [] a_copy;
    system("pause");
    return 0;

}