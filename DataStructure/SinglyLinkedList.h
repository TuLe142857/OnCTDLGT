#pragma once
#include"Node.h"

namespace SinglyLinkedList{

typedef _node::SinglyNode<int> Node;
typedef Node *Ptr;

Ptr CreateNode(){
    Ptr newnode = new Node;
    newnode->next = nullptr;
    return newnode;
}

Ptr CreateNode(int value){
    Ptr newnode = new Node;
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

void InsertFirst(Ptr &First, int value){
    Ptr newnode = CreateNode(value);
    newnode->next = First;
    First->next = newnode;
}

void InsertLast(Ptr &First, int value){
    if(First == nullptr){
        InsertFirst(First, value);
        return;
    }
    Ptr Last = First;
    while(Last->next != nullptr)
        Last = Last->next;
    Ptr newnode = CreateNode(value);
    Last->next = newnode;
}

void InsertAfter(Ptr &p, int value){
    if(p == nullptr)
        return;
    Ptr newnode = CreateNode(value);
    newnode->next = p->next;
    p->next = newnode;
}


void InsertAt(Ptr &First, Ptr p, int value){
    if(First == nullptr)
        return;
    if(First == p){
        InsertFirst(First, value);
        return;
    }

    if(p == nullptr){
        InsertLast(First, value);
        return;
    }

    Ptr prev_p = First;
    while(prev_p->next != nullptr && prev_p->next != p)
        prev_p = prev_p->next;
    
    if(prev_p->next != p)
        return;
    InsertAfter(prev_p, value);
}

//Dung cho danh sach co thu tu tang dan
void InsertOrder(Ptr &First, int value){
    Ptr prev_node = nullptr,
        next_node = First, 
        newnode = CreateNode(value);
    while(next_node != nullptr && next_node->data < value){
        prev_node = next_node;
        next_node = next_node->next;
    }

    if(next_node == First){
        newnode->next = First;
        First = newnode;
    }
    else{
        prev_node->next = newnode;
        newnode->next = next_node;
    }
}

void DeleteFirst(Ptr &First){
    if(First == nullptr)
        return;
    Ptr p = First;
    First = First->next;
    delete p;
}

void DeleteLast(Ptr &First){
    if(First == nullptr)
        return;
    if(First->next == nullptr){
        DeleteFirst(First);
        return;
    }
    Ptr prev_Last = First;
    while(prev_Last->next->next != nullptr){
        prev_Last = prev_Last->next;
    }

    delete prev_Last->next;
    prev_Last->next == nullptr;
}
void DeleteAfter(Ptr &p){
    if(p == nullptr)   
        return;
    if(p->next == nullptr)
        return;
    
    Ptr q = p->next->next;
    delete p->next;
    p->next = q;
}
void DeleteAt();

void ClearList(Ptr &First){
    Ptr p = First, q;
    while(p!=nullptr){
        q = p;
        p = p->next;
        delete q;
    }
    First == nullptr;
}

//Tim kiem tren danh sach thuong
Ptr Search1(Ptr First, int value){
    Ptr p;
    for(p = First; p!=nullptr && p->data != value; p = p->next);
    return p;
}

//Tim kiem tren danh sach co thu tu tang dan
Ptr Search2(Ptr First, int value){
    Ptr p;
    //ds tang dan nen
    for(p = First; (p != nullptr && p->data < value); p = p->next);
    if(p == nullptr || p->data == value)
        return p;
    return nullptr;
}

}