//Binary Search Tree: Find the Largest BST in Binary Tree

#include <iostream>
#include <vector>

using namespace std;

/*
Creating a struct that will store 5 information for each node
1. size of BT
2. maximum value
3. minimum value
4.size of longest binary tree traversed till now
5. If it is binary Search tree or not

*/
struct btinfo {
    int size;
    int maxi;
    int mini;
    int ans;
    bool isBST;
};

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
    void inorder(Node* root);
    btinfo largestBSTinBT(Node* root); // Structure function that will recursively check for all nodes in binary Tree.
};

void Node::inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


btinfo Node::largestBSTinBT(Node *root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1, root->data, root->data, 1, true};
    }
    // recurisively checking for left nodes and right nodes
    btinfo leftinfo= largestBSTinBT(root->left);
    btinfo rightinfo= largestBSTinBT(root->right);
    
    btinfo curremt;
    curremt.size= (1+ leftinfo.size + rightinfo.size);
    
    // checking the condition if the given tree is BST or not then updating the current values
    if(leftinfo.isBST && rightinfo.isBST && leftinfo.maxi <root->data && rightinfo.mini > root->data){
        curremt.mini= min(leftinfo.mini, min(rightinfo.mini, root->data));
        curremt.maxi= max(rightinfo.maxi, max(root->data, leftinfo.maxi));
        curremt.ans =curremt.size;
        curremt.isBST= true;
        return curremt;
    }
    curremt.ans= max(leftinfo.ans, rightinfo.ans);
    curremt.isBST= false;
    return curremt;
}

int main()
{
    /*
        15
       /   \
     20     30
    /
   5
*/
    Node BT;
    Node *root=new Node(15);
    root->left= new Node(20);
    root->right= new Node(30);
    root->left->left= new Node(5);
    cout<<"inorder Traversal of Tree 1: ";
    BT.inorder(root);
    cout<<endl;
    cout<<"Largest BST in BT "<<BT.largestBSTinBT(root).ans<<endl;
  
}

