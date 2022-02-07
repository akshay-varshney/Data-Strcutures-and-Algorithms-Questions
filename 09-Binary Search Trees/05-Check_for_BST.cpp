//Binary Search Tree: Check if a Tree is a BST

#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node(){};
    Node(int value){
        data=value;
        left=right=NULL;
    }
    Node *InsertNode(Node* root, int data);
    void inorder(Node* root);
    bool checkBST(Node* root, Node* mini, Node* maxi);
    
};

Node* Node::InsertNode(Node* root, int data)
{
    if(root==NULL){
        return new Node(data);
    }
    if(data>root->data){
        root->right=InsertNode(root->right, data);
    }
    else{
        root->left=InsertNode(root->left, data);
    }
    return root;
}

void Node::inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool Node::checkBST(Node* root, Node* mini, Node* maxi)
{
    if(root==NULL){
        return true;
    }
    if(mini!=NULL && root->data <= mini->data){
        return false;
    }
    if(maxi!=NULL && root->data>= maxi->data){
        return false;
    }
    bool leftValid= checkBST(root->left, mini, root);
    bool rightValid= checkBST(root->right, root, maxi);
    
    return (leftValid && rightValid);
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
    Node BT;
    Node* root = BT.InsertNode(root, 100);
    BT.InsertNode(root, 50);
    BT.InsertNode(root, 30);
    BT.InsertNode(root, 60);
    BT.InsertNode(root, 80);
    BT.InsertNode(root, 120);
    BT.InsertNode(root, 160);
    BT.InsertNode(root, 110);
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    cout<<endl;
    cout<<BT.checkBST(root, nullptr, nullptr)<<endl;
    
}
