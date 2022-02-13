// Heap: Convert BST to Min Heap.

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
    void inorder(Node* root);
    void Getinorder(Node* root, vector<int> &A);
    void BSTToMinHeap(Node *root, vector<int> A, int *i);
    void convertToMinHeap(Node *root);
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

void Node::inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void Node::Getinorder(Node* root, vector<int> &A)
{
    if(root)
    {
        Getinorder(root->left, A);
        A.push_back(root->data);
        Getinorder(root->right, A);
    }
}
// Pre-order Traversal just copy the data from the sorted Aay.
void Node::BSTToMinHeap(Node *root, vector<int> A, int *ind)
{
    if (root == NULL)
        return;
    root->data = A[++*ind];
    BSTToMinHeap(root->left, A, ind);
    BSTToMinHeap(root->right, A, ind);
}
 
void Node::convertToMinHeap(Node *root)
{
    vector<int> A;
    int i = -1;
    Getinorder(root, A);
    BSTToMinHeap(root, A, &i);
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
    BT.InsertNode(root, 60);
    BT.InsertNode(root, 120);
    BT.InsertNode(root, 110);
    BT.InsertNode(root, 160);
    cout<<"Inorder Traversal of Binary Search Tree: ";
    BT.inorder(root);
    cout<<endl;
    BT.convertToMinHeap(root);
    cout<<"Inorder Traversal of Min Heap: ";
    BT.inorder(root);
    cout<<endl;
    
}
