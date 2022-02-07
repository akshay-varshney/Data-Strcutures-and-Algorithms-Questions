//Binary Search Tree: Inorder Successor of the BST.

//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

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
    Node *InsertNode(Node* root, int data);
    void inorder(Node* root);
    Node* successor(Node* root, int value);
    Node* find(Node* root, int value);
    Node* findMini(Node* root);
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

void Node::inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* Node::find(Node *root, int value){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==value){
        return root;
    }
    else if(root->data >value){
        return find(root->left, value);
    }
    return find(root->right, value);
}


Node* Node::findMini(Node *root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!= NULL){
        root=root->left;
    }
    return root;
}

Node* Node::successor(Node *root, int value){
    // find the node with given value
    Node *Search=find(root, value);
    if(Search==NULL){
        return NULL;
    }
    // Move towards left most in rightsubtree
    if(Search->right !=NULL){
        return findMini(root->right);
    }
    // if it has no rightsubtree, then just store the value of of the node which is left subtree ancestor of the given node.
    else{
        Node* succesor= NULL;
        Node* ancestor=root;
        while(ancestor!=Search){
            if(Search->data <  ancestor->data){
                succesor=ancestor;
                ancestor=ancestor->left;
            }
            else{
                ancestor=ancestor->right;
            }
        }
        return succesor;
    }
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
    Node* root = BT.InsertNode(root, 100);
    BT.InsertNode(root, 50);
    BT.InsertNode(root, 30);
    BT.InsertNode(root, 60);
    BT.InsertNode(root, 120);
    BT.InsertNode(root, 110);
    BT.InsertNode(root, 160);
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    cout<<endl;
    Node* temp=BT.successor(root, 60);
    cout<<"Inorder Successor of the tree is: "<<temp->data<<endl;
}
