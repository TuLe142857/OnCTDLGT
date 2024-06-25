 #pragma once
 #include<iostream>
 using namespace std;

namespace _node{

//Danh sach lien ket don
template<typename T>
struct SinglyNode{
    T data;
    SinglyNode<T> *next = nullptr;
};

//Danh sach lk kep/vong
template<typename T>
struct DoublyNode{
    T data;
    DoublyNode<T> *prev = nullptr;
    DoublyNode<T> *next = nullptr;
};

//Cay
template<typename T>
struct TreeNode{
    T data;
    TreeNode<T> *left = nullptr;
    TreeNode<T> *right = nullptr;
};

template<typename T>
struct AVLtreeNode{
    T data;
    int bf; //balancefactor
    AVLtreeNode<T> *left = nullptr;
    AVLtreeNode<T> *right = nullptr;
};


}