//Binary Tree: Zig Zag Traversal of Tree.

//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#


#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    int height(Node* root);
    void printCurrentLevel(Node* root, int level);
    void level_order_Traversal(Node* root, int H);
    
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


int Node::height(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(leftHeight>rightHeight){
            return leftHeight+1;
        }
        else{
            return rightHeight+1;
        }
    }
}
void Node::printCurrentLevel(Node* root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->data<<" ";
    }
    else if(level%2!=0 && level>1){
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
    else if(level%2==0 && level>1){
        printCurrentLevel(root->right, level-1);
        printCurrentLevel(root->left, level-1);
    }
}

void Node::level_order_Traversal(Node* root, int H){
    for(int i=1;i<=H;i++){
        printCurrentLevel(root, i);
    }
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
    int h=BT.height(root);
    cout<<"Zig Zag Traversal of tree: ";
    BT.level_order_Traversal(root, h);
    cout<<endl;
}
