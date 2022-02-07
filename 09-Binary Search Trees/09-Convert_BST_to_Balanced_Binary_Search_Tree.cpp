//Binary Search Tree: Convert Binary Tree to Balaned Binary Tree

//https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/


#include <iostream>
#include <vector>

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
    Node* InsertNode(Node* root, int data);
    void preorder(Node* root);
    void Getpreorder(Node* root, vector<int> &arr);
    Node* ArraytoBST(vector<int> arr, int start, int end);
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

void Node::preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void Node::Getpreorder(Node* root, vector<int> &arr)
{
    if(root)
    {
        Getpreorder(root->left, arr);
        arr.push_back(root->data);
        Getpreorder(root->right, arr);
    }
}

Node* Node::ArraytoBST(vector<int> arr, int start, int end){
    
    if(start>end){
        return NULL;
    }
    
    int mid=(start+end)/2;
    Node* root= new Node(arr[mid]);
    root->left=ArraytoBST(arr, start, mid-1);
    root->right=ArraytoBST(arr, mid+1, end);
    
    return root;
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
    Node *root=NULL;
    root = BT.InsertNode(root, 100);
    BT.InsertNode(root, 50);
    BT.InsertNode(root, 30);
    BT.InsertNode(root, 10);
    BT.InsertNode(root, 120);
    
    BT.InsertNode(root, 160);
    cout<<"preorder Traversal of Tree: ";
    BT.preorder(root);
    cout<<endl;
    vector<int> arr={};
    BT.Getpreorder(root, arr);
    Node* temp=BT.ArraytoBST(arr, 0, arr.size()-1);
    cout<<"preorder Traversal of Tree: ";
    BT.preorder(temp);
    cout<<endl;

}
