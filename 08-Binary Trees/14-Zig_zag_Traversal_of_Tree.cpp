//Binary Tree: Zig Zag Traversal of Tree.

//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

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
    vector<int> zigZagTraversal(Node* root) ;
    
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


vector<int> Node::zigZagTraversal(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->data);
    Node* temp;

    int l = 1;
               
    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }

            if (l % 2 != 0) {

                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
            }
            else if (l % 2 == 0) {

                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if (temp->right)
                {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
            }
        }
        l++;
    }
    return v;
}

int main()
{
    
    /*
        Binary Tree
           3
          /   \
         2     1
       /   \  /  \
      4    5  6   7
       
        */
    
    Node BT;
    Node* root = BT.CreateNode(3);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(1);
    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right=BT.CreateNode(7);
    auto v1= BT.zigZagTraversal(root);
    for(auto it = v1.begin(); it!=v1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
