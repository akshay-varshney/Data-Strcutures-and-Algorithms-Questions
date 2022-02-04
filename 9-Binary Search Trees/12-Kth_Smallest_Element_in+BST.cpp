//Binary Search Tree: kth Smallest Element in the BST

#include <iostream>
#include <vector>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node(){};
    Node(int value){
        data=value;
        left=right=NULL;
    }
    Node* InsertNode(Node* root, int data);
    void inorder(Node* root);
    void smallestElement(Node* root, int &count);
};


Node* Node::InsertNode(Node* root, int data)
{
    if(root==NULL){
        return new Node(data);
    }
    if(data>root->data){
        root->right=InsertNode(root->right, data);
    }
    else{
        root->left=InsertNode(root->left, data);
    }
    return root;
}

void Node::inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int value=0;
void Node::smallestElement(Node* root, int &count)
{
   
    if(root==NULL || count<0){
        return;
    }
    smallestElement(root->left,count);
    count--;
    if(count==0){
        value=root->data;
        return;
    }
   
    smallestElement(root->right,count);
}

int main()
{
    /*
        20
       /   \
     8     22
    /  \
   4   12
      /   \
     10    14
*/
    Node BT;
    Node *root=NULL;
    root = BT.InsertNode(root, 20);
    BT.InsertNode(root, 22);
    BT.InsertNode(root, 8);
    BT.InsertNode(root, 4);
    BT.InsertNode(root, 12);
    BT.InsertNode(root, 14);
    BT.InsertNode(root, 10);
    cout<<"inorder Traversal of Tree 1: ";
    BT.inorder(root);
    cout<<endl;
    int count=3;
    BT.smallestElement(root,count);
    cout<<value<<endl;
}

