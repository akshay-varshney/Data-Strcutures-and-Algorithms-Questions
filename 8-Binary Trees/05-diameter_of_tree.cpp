//Binary Tree: Diameter of Tree
//https://www.cdn.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/



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
        int height(Node* root, int& H);
        void level_order_Traversal(Node *root, int H);
        void printCurrentLevel(Node* root, int level);
        int Diameter(Node* root);
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

int Node::height(Node* root, int& H){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left,H);
    int rightHeight=height(root->right,H);
    H=max(H, 1+leftHeight+rightHeight);
    return 1+max(leftHeight,rightHeight);
}
// diameter of a tree is maximum value of (left_height + right_height + 1)
int Node::Diameter(Node* root){
    int H=0;
    height(root,H);
    return H;
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
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->right->left = BT.CreateNode(5);
    root->right->right = BT.CreateNode(6);
    cout<<"Diameter of Tree is: "<<BT.Diameter(root)<<endl;
    cout<<endl;
    return 0;
}
