//Binary Search Tree: Convert Binary Tree to Binary Search Tree


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
   
};

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void GetInorder(Node* root, vector<int> &arr)
{
    if(root)
    {
        GetInorder(root->left, arr);
        arr.push_back(root->data);
        GetInorder(root->right, arr);
    }
}

void FillInorder(Node* root, const vector<int> &arr, int &index)
{
    if(root)
    {
        FillInorder(root->left, arr, index);
        root->data = arr[index++];
        FillInorder(root->right, arr, index);
    }
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    GetInorder(root, arr);
    sort(arr.begin(), arr.end());
    int index{};
    FillInorder(root, arr, index);
    arr.clear();
    return root;
}


int main()
{
    /* Binary Tree
                   8
                 /   \
                /     \
               3       5
              / \     / \
             /   \   /   \
            10    2 4     6
        */
    
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(10);
    root->left->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    cout<<"Inorder Traversal of Tree: ";
    inorder(root);
    cout<<endl;
    binaryTreeToBST(root);
    cout<<"Inorder Traversal of BST is: ";
    inorder(root);
    cout<<endl;
}
