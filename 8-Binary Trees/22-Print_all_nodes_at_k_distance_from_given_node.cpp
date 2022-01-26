//Binary Tree: Nodes at Distance K in Binary Tree

//https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    void invert(Node* &root);
    void printSubTreeNodes(Node* root, int k);
    int kthAncestorNodes(Node* root, Node* target, int k);
};

Node *temp=NULL;
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

void Node::invert(Node* &root){
    if(root==NULL){
        return;
    }
    invert(root->left);
    invert(root->right);
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
// Printing all nodes in same
void Node::printSubTreeNodes(Node *root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubTreeNodes(root->left, k-1);
    printSubTreeNodes(root->right, k-1);
}

int Node::kthAncestorNodes(Node *root, Node *target, int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printSubTreeNodes(root, k);
        return 0;
    }
    int leftdis=kthAncestorNodes(root->left, target, k);
    if(leftdis!=-1){
        if(leftdis+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubTreeNodes(root->right, k-leftdis-2);
        }
        return 1+leftdis;
    }
    
    int rightdis=kthAncestorNodes(root->right, target, k);
    if(rightdis!=-1){
        if(rightdis+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubTreeNodes(root->left, k-rightdis-2);
        }
        return 1+rightdis;
    }
    return -1;
}


int main()
{
    /*
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
    cout<<"All nodes at k distance from target node are: ";
    BT.kthAncestorNodes(root, root->left, 3);
    cout<<endl;
}
