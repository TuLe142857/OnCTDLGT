#pragma once
/*
Danh sach tuyen tinh
List1: Mang cap phat tinh
List2: Mang cap phat dong
List3: Mang con tro

@@Notice:
    -Uu diem: truy xuat nhanh
    -Nhuot diem: kich thuoc kho thay doi, them/xoa phan tu can truy van nhieu
*/

//Mang cap phat tinh
template<unsigned int size>
struct List1{
    int data[size];
    int n = 0;
};

//Mang cap phat dong
struct List2{
    int *data;
    int n;
    unsigned int size;

    List2(unsigned int size){
        this->size = size;
        data = new int [size];
        n = 0;
    }

    ~List2(){
        delete [] data;
    }

};

//Mang con tro
template<unsigned int size>
struct List3{
    int *data[size];
    int n = 0;
    ~List3(){
        for(int i = 0; i < n; i++)
            delete data[i];
    }

    bool InsertLast(int value){
        if(n == size)
            return false;
        data[n] = new int;
        data[n] = value;
        n++;
        return true;
    }

    bool InsertAt(int value, int index){
        if(!(index >= 0 && index < size))
            return false;
        if(index > n)
            index = n;
        if(index == n)
            InsertLast(value);

        //Gan con tro
        for(int i = n; i > index ; i++)
            data[i] = data[i-1];
        
        data[index] = new int;
        data[index] = value;
        n++;
        return true; 
    }


    bool DeleteLast(){
        if(n == 0)
            return false;
        delete data[--n];
        return true;
    }

    bool DeleteAt(int index){
        if(!(index >= 0 && index < n))
            return false;
        delete data[index];
        for(int i = index; i < n-1; i++)
            data[i] = data[i+1];
        n--;
        return true;
    }
};

