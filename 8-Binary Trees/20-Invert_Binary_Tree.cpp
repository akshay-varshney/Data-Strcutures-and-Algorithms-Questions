//Binary Tree: Invert a Binary Tree

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
    void inorder(Node* root);
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

void Node::inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout <<" "<< root->data;
    inorder(root->right);
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
    BT.inorder(root);
    BT.invert(root);
    cout<<endl;
    BT.inorder(root);
    cout<<endl;
}
