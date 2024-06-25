#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<windows.h>
#include<cstdlib>
using namespace std;
/*
Buble, Selection, Intersection, Quick, Heap, Merge
Sort1: Sort tren array
Sort2: Sort tren singly linked list
*/

//Sort array

//cac ham de tesst
int *CreateArr(int n, int a = 0, int b = 100){
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = a + rand()%(b-a+1);
    return arr;
}
void show_arr(int *arr, int n, int ndata_per_line = 10, int space = 5){
    for(int i = 0; i < n; i++){
        cout << setw(space) << left << arr[i];
        if((i+1)%ndata_per_line == 0 && i != (n-1)) cout << endl; 
    }
    cout << endl;
}
void copy_arr(int *a, int *a_copy,int n){
    for(int i = 0; i < n; i++)
        a_copy[i] = a[i];
}

bool check_sort(int *arr, int n){
    for(int i = 0; i < n-1; i++)
        if(arr[i] > arr[i+1]){
            cout << "Checking false at a[" << i << "] and a[" << i+1 << "]: " << endl
                 << "a[" << i << "] = " << arr[i] << endl
                 << "a[" << i+1 << "] = " << arr[i+1] << endl
                 << "ARRAY IS NOT SORTED !!!" << endl;
            return false;
        }
            
    return true;
}

void BubbleSort(int *arr, int n){
    /*
    -Sap xep noi bot
    -So sanh tung cap phan tu, day phan tu co gia tri lon ve phia sau(hoac day phan tu be hon ve phia truoc)
    ##Phan tich:
        -So lan duyet day: n-1 lan
        -Lan duyet day thu k thuc hien (n-k) phep so sanh

    -Do phuc tap: O(n^2)
    -Stable: true
    */

    int temp;

    //Dua phan tu lon ra cuoi
    // for(int i = n-1; i > 0; i--)
    //     for(int j = 0; j < i; j++)
    //         if(arr[j] > arr[j+1]){
    //             //swap
    //             temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    
    //Dua phan tu be len dau
    for(int i = 0; i < n-1; i++)
        for(int j = n-1; j > i; j--)
            if(arr[j-1] > arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
    
}

void IntersectionSort(int *arr, int n){
    /*
    -Y tuong:
        -Ta co day n phan tu da sap xep, bo phan tu a vao day de tro thanh day n+1 phan tu da sap xep
        -Ban dau, xem day co 1 pha  tu da sap xep la arr[0]
    -O(n^2)
    -Stable: true
    */

    // int i, j, temp, x;
    // for(i = 1; i < n; i++){
        
    //     x = arr[i];
    //     //them x vao day co i phan tu da co thu tu, j+1 la vi tri tuong ung cua x
    //     for(j = i-1; j >= 0; j--){
    //         if(x >= arr[j]) break;

    //         //don phan tu ve phia sau tao khoang trong chen vao
    //         arr[j+1] = arr[j]; 
    //     }
    //     arr[j+1] = x;
    // }

    int i, j, x;
    for(i = 1; i < n; i++){
        x = arr[i];
        //Bo arr[i] vao day i phan tu da sap xep arr[0], ... arr[i-1]
        //j vi tri phia truoc noi de x vao
        for(j = i-1; j >= 0; j--){
            if(x > arr[j]) break;
            //don day ve phia sau tao khoang trong cho x vao
            arr[j+1] = arr[j];
        }
        arr[j+1] = x;
    }
        
}

void SelectionSort(int *arr, int n){
    /*
    -Y tuong: Tim phan tu nho nhat trong mang, dua len dau
    -O(n^2)
    -Stable: false:
        -Viec chon phan tu nho nhat/lon nhat dua ve dau/cuoi day giu nguyen vi tri tuong doi
        -Tuy nhien, sau khi chon swap() lam sai vi tri tuong doi
    */

    // int i, j, min, index;
    // for(i = 0; i < n-1; i++){
    //     min = arr[i];
    //     index = i;
    //     for(j = i+1; j < n; j++){
    //         if(arr[j] < min){
    //             min = arr[j];
    //             index = j;
    //         }
    //     }

    //     //swap
    //     arr[index] = arr[i];
    //     arr[i] = min;
    // }

    int i, j, min, index;
    for(i = 0; i < n-1; i++){
        min = arr[i];
        index = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
    }
    
}

void _QuickSort(int *arr, int low, int high);
void QuickSort(int *arr, int n){
    _QuickSort(arr, 0, n-1);
    /*
    -Y tuong: chon mot phan tu trong mang lam pivot
    -Phan chia mang thanh 3 phan: [ a < pivot ] [ a == pivot] [ a > pivot]
    -Su dung de quy , thuat thoan phai dung khi so phan tu  = 1, 2
    */


}

void _QuickSort(int *arr, int low, int high){
    int i = low,
        j = high,
        pivot = arr[(low+high)/2],
        temp;
    while(i <= j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    /*
    sau vong while:
    i dung lien sau nhung phan tu co gia tri = pivot
    j  dung lien truoc nhung phan tu co gia tri = pivot
    */
    if(low < j) _QuickSort(arr, low, j);
    if(i < high) _QuickSort(arr, i, high);
    /*
       Tinh dung cua giai thuat khi danh sach 1, 2 phan tu
       -Giai thuat luon luon phan hoach duoc day thanh 3 phan [< pivot][== pivot][> pivot]:
       -Sau vong lap while(i <= j) : 
            -i se luon co gia tri = phan tu cuoi cung day pivot + 1
            -j se luon co gia tri = phan tu dau tien day pivot - 1
        
            a<pivot[idex1->index2]       a==pivot[index3->index4]      a>pivot[index5->index6]        
            j = index3 -1;
            i = index4 +1;
        Chung minh:
            TH 1 phan tu: true
            TH 2 phan tu: true
            TH 3 phan tu: true


        -Dua tren cac tinh chat tren, chung minh tinh dung cua thuat toan
        TH1: 1 phan tu(low==high; pivot = a[low]), sau khi phan hoach:
                pivot
            _ low==high _
            j           i
            low < j: false
            i < high: false
        
        TH2: 2 phan tu(low == high-1; pivot = arr[low]), sau khi phan hoach:
            -Neu a[low] <= a[high]:
              pivot
            _ low  high _
            j        i
            low < j: false
            i < high: false

            -Neu a[low]>a[high]: co swap
                    pivot
            _ low  high _
               j        i
            low < j: false
            i < high: false 
        TH 3, 4, ... phan tu: sau khi gio de quy se quy ve 1, 2 phan tu => dung
    */
}

void HeapSort(int *arr, int n);