//Binary Search Tree: Recover Binary Search Tree

// https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
/*
 Input Tree:
          10
         /  \
        5    8
       / \
      2   20

 In the above tree, nodes 20 and 8 must be swapped to fix the tree.
 Following is the output tree
          10
         /  \
        5    20
       / \
      2   8

 */

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
    void inorder(Node* root);
    void findlesser(Node* &root, Node* &first, Node* & mid, Node* &last, Node* &prev);
    void restoreBST(Node* root);
};


void Node::inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}


// 4 pointers to store elements, first: First time the property is violated. and it will store the prev of first time violation
// Last: last node which is showing property violation, If the elements are adjacent then the value of yf last would be NULL.
// mid: In the first time violation it will store the root node of the first time violation.
void Node::findlesser(Node* &root, Node * &first, Node* & mid, Node* &last, Node* &prev){
    if(root==NULL){
        return;
    }
    findlesser(root->left, first,mid, last, prev);
    
    if(prev && root->data< prev->data){
        // If the violation is happening for the first time or second time
        if(first==NULL){
            first=prev;
            mid=root;
        }
        // second time violation, it means that violation is not adjacent.
        else
        {
            last=root;
        }
    }
    prev=root; // previous node of the BST
    findlesser(root->right, first, mid, last, prev);
    
}

void Node::restoreBST(Node *root){
    Node* first=NULL;
    Node* mid=NULL;
    Node* last=NULL;
    Node* temp=NULL;
    findlesser(root, first, mid, last, temp);
    // This is when the swapping elements are not adjacent
    if(first && last){
        swap(&(first->data), &(last->data));
    }
    // This is when the swapping element are adjacent
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}


int main()
{
    /*
        6
       /  \
     9     3
    /  \    \
   1    4    13
      
     */
    Node BT;
    Node *root=new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left =new Node(1);
    root->left->right= new Node(4);
    root->right->right= new Node(13);
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    cout<<endl;
    BT.restoreBST(root);
    cout<<"Inorder Traversal of  Restored BST: ";
    BT.inorder(root);
    cout<<endl;
  
}

