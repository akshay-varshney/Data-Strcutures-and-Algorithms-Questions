//Binary Search Tree: Merge Two Binary Seach Trees

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
    void Getinorder(Node* root, vector<int> &arr);
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

void Node::inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void Node::Getinorder(Node* root, vector<int> &arr)
{
    if(root)
    {
        Getinorder(root->left, arr);
        arr.push_back(root->data);
        Getinorder(root->right, arr);
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
    cout<<"inorder Traversal of Tree 1: ";
    BT.inorder(root);
    cout<<endl;
    /*
     Binary Tree 2
        25
       /   \
     15     34
    /         \
   8           92
        
     
*/
    Node *root1=NULL;
    root1 = BT.InsertNode(root1, 25);
    BT.InsertNode(root1, 15);
    BT.InsertNode(root1, 8);
    BT.InsertNode(root1, 34);
    BT.InsertNode(root1, 92);
    cout<<"inorder Traversal of Tree 2: ";
    BT.inorder(root1);
    cout<<endl;
    
    vector<int> arr={};
    BT.Getinorder(root, arr);
    BT.Getinorder(root1, arr);
    sort(arr.begin(), arr.end());
    Node* temp=BT.ArraytoBST(arr, 0, arr.size()-1);
    cout<<"inorder Traversal of Tree: ";
    BT.inorder(temp);
    cout<<endl;

}
// Time: O(log(m+n)) and Space: O(m+n)
