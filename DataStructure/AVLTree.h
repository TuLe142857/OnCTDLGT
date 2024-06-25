#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
using namespace std;
/*
-Cay nhi phan tim kiem(BST):
-Cay nhi phan tim kiem can bang(AVL):
    -La cay nhi phan tim kiem
    -Voi moi nut p cua cay, abs(height(p->left) - height(p->right)) <= 1
-Cay nhi phan tim kiem can bang hoan toan:
    -La cay nhi phan tim kiem
    -Voi moi nut p cua cay: abs(countNodes(p->left) - countNodes(p->right)) <= 1;

AVL:
    insert
    delete
    search
    traverse

Doi voi AVL tree:
    -bf(balance factor) = heightleft - heightright
    => insert mat can bang khi:
        -insert letf node bf = 1
        -insert right node bf = -1
*/

namespace AVLtree_bf{
    struct Node{
        int key;
        int infor;
        int bf;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    typedef Node *Ptr;

    Ptr CreateNode(int key, int info, int bf, Ptr left, Ptr right){
        Ptr node = new Node;
        node->key = key;
        node->infor = info;
        node->bf = bf;
        node->left = left;
        node->right = right;
        return node;
    }

    int Height(Ptr root){
        if(root == nullptr)
            return 0;
        return 1 + std::max(Height(root->left), Height(root->right));
    }

    bool checkBST(Ptr root){
        if(root == nullptr)
            return true;
        
        bool l = true, r = true;
        if(root->left != nullptr)
            l = (root->left->key < root->key) && checkBST(root->left);
        if(root->right != nullptr)
            r = (root->right->key > root->key) && checkBST(root->right);
        return r&&l;
        
    }

    bool checkBalance(Ptr root){
        if(abs(Height(root->right) - Height(root->left)) > 1) 
            return false;
        return checkBalance(root->right) && checkBalance(root->left);
    }

    bool checkAVL(Ptr root){
        return checkBalance(root) && checkBST(root);
    }


    //Insert, Delete, Search

    //=============== Search
    Ptr Search(Ptr root, int key){
        Ptr p = root;
        while(p != nullptr && p->key != key){
            if(key < p->key)
                p = p->left;
            else 
                p = p->right;
        }
        return p;
    }

    //========= Insert

    //Lech phai => xoay trai
    Ptr RotateLeft(Ptr node){
        if(node == nullptr || node->right == nullptr){
            return nullptr;
        }
        Ptr p = node->right;
        node->right = p->left;
        p->left = node;
        return p;
        /*
                node
            nl      nr = p
                 pleft    pright
                              newnode

                     p
             node        pright
          nl    pleft       newnode
        */
    }

    Ptr RotateRight(Ptr node){
        if(node == nullptr || node->left == nullptr){
            return nullptr;
        }

        Ptr p = node->left;
        node->left = p->right;
        p->right = node;
        return p;
    }

    void Insert(Ptr &root, int key, int info){
        Ptr ya, fya, s,
            p, fp, q;
        int imbal;

        fya = nullptr;  ya = root;
        fp = nullptr;   p = root;
        while(p != nullptr){
            if(key == p->key)
                return;
            else if(key < p->key)
                q = p->left;
            else    
                q = p->right;
            if(q != nullptr && q->bf != 0){
                fya = p;
                ya = q;
            }
            fp = p;
            p = q;
        }

        //Create && Insert
        q = CreateNode(key, info, 0, nullptr, nullptr);
        if(fp == nullptr){
            root = q;
            return;
        }
        if(key < fp->key)
            fp->left = q;
        else    
            fp->right = q;
        
        //Imbal, cap nhat bf
        if(key < ya->key){
            imbal = 1;
            p = ya->left;
        }else{
            imbal = -1;
            p = ya->right;
        }
        s = p;  //s: nut con ya theo huong lech
        //cap nhat bf tu sau ya->truoc q
        while(p != q){
            if(key < p->key){
                p->bf = 1;
                p = p->left;
            }else{
                p->bf = -1;
                p = p->right;
            }
        }   

        //Kiem tra can bang

        if(ya->bf == 0){
            ya->bf = imbal;
            return;
        }
        if(ya->bf != imbal){
            ya->bf = 0;
            return;
        }

        //TH cay mat CB
        //Xoay don
        if(ya->bf == imbal)
        {
            if(imbal == 1)
                //lech trai-trai => xoay phai ya
                p = RotateRight(ya);
            else
                //lech phai-phai => xoay trai ya
                p = RotateLeft(ya);
            
            //chinh bf
            ya->bf = 0;
            s->bf = 0;
        }
        //Xoay kep
        else//ya->bf != imbal
        {   
            
            if(imbal == 1){
                //lech phai-trai => xoay phai s, xoay trai ya
                ya->left = RotateRight(s);
                p = RotateRight(ya);
            }
            else
            {
                //lech trai-phai => xoay trai s, xoay phia ya
                ya->right = RotateLeft(s);
                p = RotateRight(ya);
            }

            //chinh bf
            if(p->bf == 0){
                //p la nut moi them vao
                //=> ban dau s la node la
                //=> sau khi them bf s = 0, bf ya = 0
                s->bf = 0;
                ya->bf = 0;
            }
            else if(p->bf == imbal){
                //insert new node vao b cung chieu imbal
                ya->bf = -imbal;
                s->bf = 0;
            }else{
                ya->bf = 0;
                s->bf = imbal;
            }

            p->bf = 0;
        }

        if(fya == nullptr){
            root = p;
            return;
        }
        if(imbal == 1)
            fya->left = p;
        else    
            fya->right = p;

    }


    //========= Delete
    Ptr DeleteByKey(Ptr root, int key);

}