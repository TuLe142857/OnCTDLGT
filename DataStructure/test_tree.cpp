#include"Tree.h"
using namespace Tree;
int main(){
    //srand(time(0));
    int n, rootvalue, a, b;
    // cout << "Nhap du lieu:" << endl;
    // cout << "n = "; cin >> n;
    // cout << "rootvalue = "; cin >>rootvalue;
    // cout << "a = "; cin >> a;
    // cout << "b = "; cin >> b;
    n = 10;rootvalue = 5;a = 0; b = 10;

    Ptr root = Create_Tree(n, rootvalue, a, b);
    system("pause");

    system("cls");

    print_tree(root, 0);
    cout << "Total Nodes = " << countNodes(root) << endl;
    cout << "Total Leaves = " << countLeaves(root) << endl;
    cout << "Height = " << Height(root) << endl;
    system("pause");
    //system("cls");

    cout << "Preorder" << endl;
    dequy::PreOrder(root);cout << endl;
    khudequy::PreOrder(root);cout << endl;

    cout << endl;
    cout << "Inorder" << endl;
    dequy::InOrder(root);cout << endl;
    khudequy::InOrder(root);cout << endl;


    cout << endl;
    cout << "Postorder" << endl;
    dequy::PostOrder(root);cout << endl;
    khudequy::PostOrder(root);cout << endl;
    
   
    // int k;
    // cin >> k;
    // DeleteByValue(k, root);

    // system("pause");
    // system("cls");
    // print_tree(root, 0);
    // cout << "Total Nodes = " << countNodes(root) << endl;
    // cout << "Total Leaves = " << countLeaves(root) << endl;
    // cout << "Height = " << Height(root) << endl;
    

    DeleteTree(root);
    system("pause");
    return 0;
}