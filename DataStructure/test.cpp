#include<iostream>
using namespace std;
#define MAX 5

void change(int **arr, int n, int index, int newvalue){
    if(index >= 0 && index < n);
    *arr[index] = newvalue;
    arr[index] = new int;
    *arr[index] = 5;
    
}

struct List{
    int *data[MAX];
    int n = 0;
};


void test(List ds){
    // cout << "address of **data: " << ds.data << endl;
    // cout << "address of *data[0]: " << ds.data[0] << endl; 
    //cout << "new" << endl;
    *(ds.data[0]) = 2;
    ds.data[0] = new int;
    *ds.data[0] = 5;
    // cout << *ds.data[0] << endl;

}



int main(){
    int *arr[5];
    cout << arr[0] << endl;
    cout << arr << endl;
    cout << &arr << endl;

    cout << endl;

    int **b = new int*[3];
    cout << &b[0] << endl;
    cout << b << endl;
    cout << &b << endl;
    
}