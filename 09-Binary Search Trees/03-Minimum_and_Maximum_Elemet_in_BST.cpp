//Binary Search Tree: Find Minimum and Maximum Element in BST



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
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    void inorder(Node* root);
    void findMiniMaxi(Node* root);
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


void Node::findMiniMaxi(Node *root){
    Node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    cout<<"Minimum element is "<<temp->data<<endl;
    temp=root;
    while(temp->right){
        temp=temp->right;
    }
    cout<<"Maximum element is: "<<temp->data<<endl;
    delete temp;
}


int main()
{
    /*
        100
       /   \
     50     120
    /  \    /   \
   30   60  110  160
                 /  \
                150  180
    
     
*/
    Node BT;
    Node* root = BT.InsertNode(root, 100);
    BT.InsertNode(root, 50);
    BT.InsertNode(root, 30);
    BT.InsertNode(root, 60);
    BT.InsertNode(root, 80);
    BT.InsertNode(root, 120);
    BT.InsertNode(root, 160);
    BT.InsertNode(root, 150);
    BT.InsertNode(root, 180);
    BT.InsertNode(root, 110);
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    cout<<endl;
    BT.findMiniMaxi(root);
    
}
