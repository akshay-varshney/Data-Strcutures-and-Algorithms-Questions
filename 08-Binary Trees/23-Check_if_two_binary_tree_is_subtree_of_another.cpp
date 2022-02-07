//Binary Tree: Check if a binary tree is subtree of another binary tree

//https://www.cdn.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    void invert(Node* &root);
    bool isSubTree(Node* root1, Node* root2);
    bool areIdenticalTree(Node* root1, Node* root2);
};

Node *temp=NULL;
Node* Node::CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Node::invert(Node* &root){
    if(root==NULL){
        return;
    }
    invert(root->left);
    invert(root->right);
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
}

bool Node::areIdenticalTree(Node *root1, Node *root2){
    if (root1==NULL && root2== NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    return ((root1->data==root2->data) && areIdenticalTree(root1->left, root2->left) && areIdenticalTree(root1->right, root2->right));
}


bool Node::isSubTree(Node *root1, Node *root2){
    if(root2==NULL){
        return true;
    }
    if(root1==NULL){
        return false;
    }
    if(areIdenticalTree(root1, root2)){
        return true;
    }
    return (isSubTree(root1->left, root2) || isSubTree(root1->right, root2));
}

int main()
{
    /*
        1
       /   \
      2     3
    /   \  /  \
   4    5  6   7
    
     
*/
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right=BT.CreateNode(7);
    cout<<"The given Trees subtree : ";
    Node* root1= BT.CreateNode(3);
    root1->left=BT.CreateNode(6);
    root1->right=BT.CreateNode(7);
    cout<<BT.isSubTree(root, root1);
    cout<<endl;
}
