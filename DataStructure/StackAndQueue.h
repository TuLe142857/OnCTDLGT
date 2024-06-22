#pragma once
#include"Node.h"
#include<iostream>
using namespace std;

/*
Stack1, Queue1: Su dung mang cap phat tinh
Stack2, Queue2: Su dung danh sach lien ket
    -Stack: push, pop cung cho
    -Queue: push, pop khac cho
*/

//Stack, Queue dung mang cap phat tinh

//push:insert last, pop:delete last
template<int size, typename T>
class Stack1{
private:
    T data[size];
    int sp = -1;
public:
    bool empty(){
        return sp == -1;
    }
    bool full(){
        return sp == size-1;
    }

    bool push(T value){
        if(full())
            return false;
        data[++sp] = value;
        return true;
    }

    bool pop(T &x){
        if(empty())
            return false;
        x = data[sp--];
        return true;
    }
};

//push: insert rear(last)
//pop: delete front(first)
template<int size, typename T>
class Queue1{
private:
    T data[size];
    int front = -1, rear = -1;
public:
    bool empty(){
        //Khong pop duoc thi empty
        return front == -1;
    }

    bool full(){ 
        //2TH:
        //front == 0, rear == size-1
        //front ngay sau rear

        return((front - rear == 1)||(rear - front +1 == size))
    }

    bool push(T value){
        if(full)
            return false;
        
        if(front == -1){
            front = 0;
            rear = -1;
        }
        if(rear == size-1)
            rear = -1;

        data[++rear] = value;

        return true;
    }

    bool pop(T &x){
        if(empty())
            return false;
        x = data[front];
        if(front == rear){
            front = -1;
        }else{
            front ++;
            if(front == size)
                front = 0;
        }
        return true;
    }
};


//Stack, Queue dung danh sach lien ket don

//Stack push:insert first, pop:delete first
template<typename T>
class Stack2{
private:
    _node::SinglyNode<T> *First;
public:
    Stack2(){
        First = nullptr;
    }
    ~Stack2(){
        _node::SinglyNode<T> *p = First, *q;
        while(p != nullptr){
            q = p;
            p = p->next;
            delete q;
        }
    }

    bool empty(){
        return(First == nullptr);
    }

    void push(T data){
        _node::SinglyNode<T> *newnode = new _node::SinglyNode<T>;
        newnode->data = data;
        newnode->next = First;
        First = newnode;
    }

    bool pop(T &data){
        if(First == nullptr)
            return false;
        data = First->data;

        _node::SinglyNode<T> *p = First;
        First = First->next;
        delete p;
        return true;
    }
};


//Queue: push = insert last; pop = delete first
template<typename T>
class Queue2{
private:
    _node::SinglyNode<T> *First, *Last;
public:
    Queue2(){
        First = nullptr;
        Last = nullptr;
    }
    ~Queue2(){
        _node::SinglyNode<T> *p = First, *q;
        while(p != nullptr){
            q = p;
            p = p->next;
            delete q;
        }
    }

    bool empty(){
        return (First == nullptr);
    }

    void push(T data){
        _node::SinglyNode<T> *newnode = new _node::SinglyNode<T>;
        newnode->data = data;
        newnode->next = nullptr;
        if(Last == nullptr){
            First = newnode;
            Last = newnode;
        }
        else{
            Last->next = newnode;
            Last = Last->next;
        }
    }

    bool pop(T &data){
        if(First == nullptr)
            return false;

        data = First->data;
        _node::SinglyNode<T> *p = First;
        First = First->next;
        delete p;
        if(First == nullptr)
            Last = nullptr;
        return true;
    }
};