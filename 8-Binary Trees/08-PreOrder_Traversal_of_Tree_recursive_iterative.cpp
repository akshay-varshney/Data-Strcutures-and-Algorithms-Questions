//Binary Tree: Inorder traversal of Tree using Iterative and Recursive way
//Preorder (Root, Left, Right)


#include <iostream>
#include <stack>
using namespace std;

class Node {
    
    public:
        int data;
        Node* left;
        Node* right;
        Node *CreateNode(int data);
        Node *InsertNode(Node* root, int data);
        void preorder(Node* root);
        void recursive_Preorder(Node* root);
};

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
void Node::preorder(Node* root)
{
    if (root == NULL)
        return;
    cout <<" "<< root->data;
    preorder(root->left);
    preorder(root->right);
}

// using stack to get the last elemnt
void Node::recursive_Preorder(Node *root){
    if(root==NULL){
        return;
    }
    stack<Node*> S1;
    Node* temp=root;
    S1.push(root);
    while (!S1.empty()) {
        temp=S1.top();
        S1.pop();
        cout<<temp->data<<" ";
        if(temp->right){
            S1.push(temp->right);
        }
        if(temp->left){
            S1.push(temp->left);
        }
    }
}
    


int main()
{
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->right->left = BT.CreateNode(5);
    root->right->right=BT.CreateNode(6);
    root->right->left->left = BT.CreateNode(7);
    root->right->left->right = BT.CreateNode(8);
    
    cout <<"Preorder Traversal of tree: ";
    BT.preorder(root);
    cout<<endl;
    cout<<"Recursive Preorder Traversal: "<<endl;
    BT.recursive_Preorder(root);
    cout<<endl;
}
