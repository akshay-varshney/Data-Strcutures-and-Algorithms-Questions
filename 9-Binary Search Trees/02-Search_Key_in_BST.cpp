//Binary Search Tree: Find/Search Key in BST


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
    BST* find_Key(BST* root, int key);
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
    cout<<root->data<<" ";
    inorder(root->right);
}

BST* BST::find_Key(BST *root, int key){
    if(root==NULL || key==root->data){
        return root;
    }
    else if(key>root->data){
        return find_Key(root->right, key);
    }
    else{
        return find_Key(root->left, key);
    }
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
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    cout<<endl;
    BST*temp=BT.find_Key(root, 160);
    if(temp==NULL)
        cout<<"Key does not found"<<endl;
    else
        cout<<"Key Found: "<<temp->data<<endl;
}
