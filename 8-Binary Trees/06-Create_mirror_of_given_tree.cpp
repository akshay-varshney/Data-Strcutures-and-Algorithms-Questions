//Binary Tree: Mirror of Tree
//https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
#include <iostream>

using namespace std;

class Node {
    
    public:
        int data;
        Node* left;
        Node* right;
        Node *CreateNode(int data);
        Node *InsertNode(Node* root, int data);
        Node* mirror(Node* root);
        void inorder(Node* root);
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

// Swapping the left and right node of the tree.
Node* Node::mirror(Node* root){
    if(root==NULL){
        return root;
    }
    if(root->left || root->right)
    {
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    if(root->left){
        mirror(root->left);
    }
    if(root->right){
        mirror(root->right);
    }
    return root;
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
    Node *Mirror=BT.mirror(root);
    cout<<"Mirror: ";
    BT.inorder(Mirror);
    cout<<endl;
}
