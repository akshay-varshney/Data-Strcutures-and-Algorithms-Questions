//Binary Tree: Convert a given tree to its Sum Tree

//https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/


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
    int sumTree(Node* root);//, stack<int> &S);
    void postorder(Node* root);
    
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

int Node::sumTree(Node* root)//, stack<int> &S)
{
    if(root == NULL)
        return 0;
    int first = root->data;
    root->data = sumTree(root->left) + sumTree(root->right);

    return root->data + first;
}
void Node::postorder(Node* root)
{
    if (root == NULL)
        return;
   
    postorder(root->left);
    postorder(root->right);
    cout <<" "<< root->data;
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
    stack<int> S;
    BT.postorder(root);
    cout<<endl;
    
    BT.sumTree(root);//,S);
    BT.postorder(root);
    cout<<endl;

}
