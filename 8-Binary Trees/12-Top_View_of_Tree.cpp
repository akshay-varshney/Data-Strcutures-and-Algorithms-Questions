//Binary Tree: Top View of the Tree.

//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#


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
        void rightView(Node* root, int level, int &last_level, vector<int> &V1);
        void leftView(Node* root, int level, int &last_level, vector<int>& V2);
        void TopView(Node* root);
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

void Node::leftView(Node* root, int level, int &last_level, vector<int>& V1)
{
    if (root == nullptr) {
        return ;
    }
    if (last_level < level)
    {
        V1.push_back(root->data);
        last_level = level;
    }
    leftView(root->left, level + 1, last_level, V1);
    leftView(root->right, level + 1, last_level, V1);
}

void Node::rightView(Node* root, int level, int &last_level, vector<int>& V2)
{
    if (root == nullptr) {
        return ;
    }
    if (last_level < level)
    {
        V2.push_back(root->data);
        last_level = level;
    }
    rightView(root->right, level + 1, last_level, V2);
    rightView(root->left, level + 1, last_level, V2);

}

void Node::TopView(Node* root)
{
    int last_level = 0;
    vector<int> right;
    vector<int> left;
    rightView(root, 1, last_level, right);
    last_level=0;
    leftView(root, 1, last_level, left);
    reverse(left.begin(), left.end());
    right.erase(right.begin());
    for(auto it=right.begin();it!=right.end();it++){
        left.push_back(*it);
    }
    right.clear();
    cout<<"Top View of Tree: ";
    for(auto it=left.begin(); it!=left.end(); it++){
        cout<<*it<<" ";
    }
    left.clear();
}

int main()
{
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right=BT.CreateNode(7);
    BT.TopView(root);
    cout<<endl;
}
