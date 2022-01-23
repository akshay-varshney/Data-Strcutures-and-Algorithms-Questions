//Binary Tree: Left View of the Tree.
//https://www.geeksforgeeks.org/print-left-view-binary-tree/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
    
    public:
        int data;
        Node* left;
        Node* right;
        Node *CreateNode(int data);
        Node *InsertNode(Node* root, int data);
        void leftView(Node* root, int level, int &last_level);
        void leftView(Node* root);
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

void Node::leftView(Node* root, int level, int &last_level)
{
    if (root == nullptr) {
        return;
    }
    if (last_level < level)
    {
        cout << root->data << " ";
        last_level = level;
    }
    leftView(root->left, level + 1, last_level);
    leftView(root->right, level + 1, last_level);
}

void Node::leftView(Node* root)
{
    int last_level = 0;
    leftView(root, 1, last_level);
}

int main()
{
    /*
        Binary Tree
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
    root->left->right = BT.CreateNode(4);
    root->left->right->right = BT.CreateNode(5);
    root->left->right->right->right=BT.CreateNode(6);
    cout<<"Left View of Tree: ";
    BT.leftView(root);
    cout<<endl;
}
