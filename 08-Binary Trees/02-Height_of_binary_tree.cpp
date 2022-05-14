//Binary Tree: Height of Tree


#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node *CreateNode(int data);
        Node *InsertNode(Node* root, int data);
        void print_Node(Node *root);
        int height(Node* root);
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



void Node::print_Node(Node *temp)
{
    if (temp == NULL)
        return;

    print_Node(temp->left);
    cout << temp->data << " ";
    print_Node(temp->right);
}

int Node::height(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

int main()
{
    /*
          Binary Tree
             1
            /   \
           2     3
         /      /  \
        4      5    6
        
          */
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->left->left = BT.CreateNode(3);
    root->right = BT.CreateNode(4);
    root->right->left = BT.CreateNode(5);
    root->right->right = BT.CreateNode(6);
    cout<<"Tree :";
    BT.print_Node(root);
    cout << endl;
    cout<<"height of Tree: "<<BT.height(root)<<endl;
    return 0;
}
