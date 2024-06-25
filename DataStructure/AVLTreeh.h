#pragma once
#include<iostream>
#include<math.h>
using namespace std;

namespace AVLtree_h{

struct Node{
    int key, info, height;
    Node* left = nullptr, *right = nullptr;
};
typedef Node* Ptr;

void DeleteTree(Ptr &root){
    if(root != nullptr){
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
        root == nullptr;
    }
}

struct Tree{
    Ptr root;
    Tree(Ptr root = nullptr){
        this->root = root;
    }
    ~Tree(){
        DeleteTree(root);
    }
};

Ptr CreateNode(int key, int info, int height, Ptr left, Ptr right){
    Ptr node = new Node;
    node->key = key;
    node->info = info;
    node->height = height;
    node->left = left;
    node->right = right;
    return node;
}


//Inserrt
Ptr LeftRotate(Ptr node){

}






}