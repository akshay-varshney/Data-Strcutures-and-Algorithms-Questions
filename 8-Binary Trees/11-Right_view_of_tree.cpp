//Binary Tree: Right View of Tree
//https://www.geeksforgeeks.org/print-right-view-binary-tree-2/


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
        void rightView(Node* root, int level, int &last_level);
        void rightView(Node* root);
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

void Node::rightView(Node* root, int level, int &last_level)
{
    if (root == nullptr) {
        return;
    }
    if (last_level < level)
    {
        cout << root->data << " ";
        last_level = level;
    }
    rightView(root->right, level + 1, last_level);
    rightView(root->left, level + 1, last_level);
    
}

void Node::rightView(Node* root)
{
    int last_level = 0;
    rightView(root, 1, last_level);
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
    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right=BT.CreateNode(7);

    cout<<"Right View of Tree: ";
    BT.rightView(root);
    cout<<endl;
}
