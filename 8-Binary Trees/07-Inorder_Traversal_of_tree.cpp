//Binary Tree: Inorder traversal of Tree using Iterative and Recursive way
// Inorder (Left, Root, Right)


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
        void inorder(Node* root);
        void recursive_inorder(Node* root);
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
void Node::inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout <<" "<< root->data;
    inorder(root->right);
}

// using stack to get the last elemnt
void Node::recursive_inorder(Node *root){
    if(root==NULL){
        return;
    }
    stack<Node*> S1;
    Node* temp=root;
    while (!S1.empty() || temp!=NULL) {
        while(temp!=NULL){
            S1.push(temp);
            temp=temp->left;
        }
        temp=S1.top();
        S1.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
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
    root->right->right = BT.CreateNode(6);
    root->right->right->left = BT.CreateNode(9);
    cout <<"Inorder of original tree: ";
    BT.inorder(root);
    cout<<endl;
    cout<<"Recursive Inorder Traversal: "<<endl;
    BT.recursive_inorder(root);
}
