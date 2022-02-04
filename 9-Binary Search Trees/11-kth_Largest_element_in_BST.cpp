//Binary Search Tree: kth Largest Element in BST

#include <iostream>

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
    void findElement(Node* root, int &count);
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
void Node::findElement(Node* root, int &count)
{
   
    if(root==NULL || count<0){
        return;
    }
    findElement(root->right,count);
    count--;
    if(count==0){
        value=root->data;
        return;
    }
   
    findElement(root->left,count);
}

int main()
{
    /*
        100
       /   \
     50     120
    /  \    /   \
   30   60  110  160
        
     
*/
    Node BT;
    Node *root=NULL;
    root = BT.InsertNode(root, 100);
    BT.InsertNode(root, 50);
    BT.InsertNode(root, 30);
    BT.InsertNode(root, 60);
    BT.InsertNode(root, 120);
    BT.InsertNode(root, 110);
    BT.InsertNode(root, 160);
    cout<<"inorder Traversal of Tree 1: ";
    BT.inorder(root);
    cout<<endl;
    int count=2;
    BT.findElement(root,count);
    cout<<value<<endl;
}

