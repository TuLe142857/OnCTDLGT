#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<windows.h>
#include<cstdlib>
using namespace std;
#include"Node.h"


namespace Tree{

// void gotoxy(short x,short y)
// {
//         HANDLE hConsoleOutput;
//         COORD Cursor_an_Pos = { x,y};
//         hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//         SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
// } 
    
typedef _node::TreeNode<int> Node;
typedef Node* Ptr;

void Insert(Ptr &root, int value){
    if(root == nullptr){
        Ptr newnode = new Node;
        newnode->data = value;
        newnode->left = nullptr;
        newnode->right = nullptr;
        root = newnode;
    }else{
        if(root->data >= value)
             Insert(root->left, value);
        else  Insert(root->right, value);
    }
}

void print_tree(Ptr root, int type,  int space = 5, int incre = 5){
    if(root == nullptr){
        cout << setw(space) << "";
        switch(type){
            case 0:{
                break;
            }
            case -1:{
                cout << "\\";
                break;
            }
            case 1:{
                cout << "/";
                break;
            }
        }
        cout << "null" << endl;
        return ;
    }
    // if(root->right != nullptr)
    print_tree(root->right,1,  space + incre);


    cout << setw(space) << "";
    switch(type){
        case 0:{
            break;
        }
        case -1:{
            cout << "\\";
            break;
        }
        case 1:{
            cout << "/";
            break;
        }
    }
    cout << root->data <<  endl;
    //left
    // if(root->left != nullptr)
    print_tree(root->left,-1,  space + incre);
}

Ptr Create_Tree(int n, int rootvalue, int a, int b){
    cout << "Create: " << endl;
    if(n <= 0) return nullptr;
    Ptr root = nullptr;
    Insert(root, rootvalue);
    cout << rootvalue << endl;
    int k;
    for(int i = 0; i < n-1; i++){
        k = a + rand()%(b-a+1);
        Insert(root, k);
        cout << k << endl;
    }
    return root;
}

void DeleteTree(Ptr &root){
    if(root->left != nullptr)
        DeleteTree(root->left);
    if(root->right != nullptr)
        DeleteTree(root->right);
    delete root;
}

//count node dung stack, Inorder LNR
int countNode1(Ptr root){
    Ptr stack[500];
    int sp = -1;
    int count  = 0;

    Ptr p = root;
    while(1){
        while(p != nullptr){
            stack[++sp] = p;
            p = p->left;
        }
        if(sp != -1){
            p = stack[sp--];
            count ++;
            p = p->right;
        }else break;
    }
    return count;
}

int countNodes(Ptr root){
    if(root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int countLeaves(Ptr root){
    if(root == nullptr)return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int max(int a, int b){
    return (a > b)?a:b;
}
int Height(Ptr root){
    if(root == nullptr)
        return 0;
    return 1 + max(Height(root->left), Height(root->right));
}

/*
Cay nhi phan dung: moi nut trung gian co 2 nut con
*/
bool isTrueBT(Ptr root);


/*
Cay nhi phan day chieu cao d:
    -Cay nhi pha  dung
    -Cac nut la co muc la d
*/
bool isFullBT(Ptr root);


//delete 
/*
TH1: nut can xoa la nut la
TH2: nut can xoa co 1 cay con
TH3: nut can xoa co 2 cay con
*/
void  remove_case3(Ptr &rp, Ptr &r){
    if(r->left != nullptr){
        remove_case3(rp, r->left);
    }
    else{
        rp->data = r->data;
        rp = r;
        r = r->right;
    }
}
void DeleteByValue(int x, Ptr &p){
    if(p == nullptr) return;
    if(x < p->data)
        DeleteByValue(x, p->left);
    else if (x > p->data)
        DeleteByValue(x, p->right);
    else{
        Ptr rp = p;//remove p
        if(p->right == nullptr)
            p = p->left;
        else if(p->left == nullptr)
            p = p->right;
        else{
            Ptr *r = &p->right;
            while((*r)->left != nullptr)
                r = &((*r)->left);
            rp->data = (*r)->data;
            rp = (*r);
            (*r) = (*r)->right;
            //remove_case3(rp, p->right);
        }

        delete rp;
    } 

}




//=====================Traverse
namespace dequy{

    //NLR
    void PreOrder(Ptr root, unsigned int space = 5){
        if(root != nullptr){
            cout << setw(space) << left << root->data;
            PreOrder(root->left, space);
            PreOrder(root->right, space);
        }
    }

    //LNR
    void InOrder(Ptr root, unsigned int space = 5){
        if(root != nullptr){
            InOrder(root->left, space);
            cout << setw(space) << left << root->data;
            InOrder(root->right, space);
        }
        
    }

    //LRN
    void PostOrder(Ptr root, unsigned int space = 5){
        if(root != nullptr){
            PostOrder(root->left, space);
            PostOrder(root->right, space);
            cout << setw(space) << left << root->data;
        }
        
    }
}

//dung stack
namespace khudequy{
    //NLR
    void PreOrder(Ptr root, unsigned int space = 5){
        Ptr stack[500];
        int sp = -1;
        Ptr p = root;
        while(p != nullptr){
            cout << setw(space) << left << p->data;
            if(p->right != nullptr)
                stack[++sp] = p->right;
            if(p->left != nullptr)
                p = p->left;
            else if(sp != -1)
                p = stack[sp--];
            else break;
        }
    }

    //LNR
    void InOrder(Ptr root, unsigned int space = 5){
        Ptr stack[500];
        int sp = -1;
        Ptr p = root;
        while(1){
            while(p != nullptr){
                stack[++sp] = p;
                p = p->left;
            }
            if(sp != -1){
                p = stack[sp--];
                cout << setw(space) << left << p->data;

                p = p->right;
            }else break;
        }
    }
    

    //LRN
    void PostOrder(Ptr root, unsigned int space = 5){
        enum nodetype{N, R};
        struct stacknode{
            Ptr ptr;
            int type;
        };

        stacknode stack[500];
        int sp = -1;
        Ptr p = root;
        int ptype = R;
        while(1){
            while(p != nullptr && ptype == R){
                sp++;
                stack[sp].ptr = p;
                stack[sp].type = N;

                if(p->right != nullptr){
                    sp++;
                    stack[sp].ptr = p->right;
                    stack[sp].type = R;
                }
                p = p->left;
            }

            if(p != nullptr){
                cout << setw(space) << left << p->data;
            }

            if(sp != -1){
                p = stack[sp].ptr;
                ptype = stack[sp].type;
                sp--;
            }else break;
        }
    }
}
}