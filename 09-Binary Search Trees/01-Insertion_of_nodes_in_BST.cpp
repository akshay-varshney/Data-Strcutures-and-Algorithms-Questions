//Binary Search Tree: Insertion of nodes in BST


#include <iostream>

using namespace std;

class BST {

public:
    int data;
    BST* left;
    BST* right;
    BST(){};
    BST(int value){
        data=value;
        left=right=NULL;
    }
    BST *CreateBST(int data);
    BST *InsertBST(BST* root, int data);
    void inorder(BST* root);

};

BST* BST::InsertBST(BST* root, int data)
{
    if(root==NULL){
        return new BST(data);
    }
    if(data>root->data){
        root->right=InsertBST(root->right, data);
    }
    else{
        root->left=InsertBST(root->left, data);
    }
    return root;
}

void BST::inorder(BST *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

int main()
{
    /*
        100
       /   \
     50     120
    /  \    /   \
   30   60  110  160
    
     
*/
    BST BT;
    BST* root = BT.InsertBST(root, 100);
    BT.InsertBST(root, 50);
    BT.InsertBST(root, 30);
    BT.InsertBST(root, 60);
    BT.InsertBST(root, 120);
    BT.InsertBST(root, 160);
    BT.InsertBST(root, 110);
    BT.inorder(root);
}
