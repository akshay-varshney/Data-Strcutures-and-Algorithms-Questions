//Binary Search Tree: LCA in BST


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
    Node* lca(Node* root, int n1, int n2);
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


Node* Node::lca(Node* root ,int n1 ,int n2 )
{
    if(root->data==n1 || root->data==n2)
        return root;
    if(root==NULL)
        return NULL;
    
   Node *LEFT=NULL;
   Node * RIGHT=NULL;
   if(root->left)
       LEFT=lca(root->left, n1, n2);
   if(root->right)
       RIGHT= lca(root->right, n1, n2);
   if(LEFT!=NULL && RIGHT!=NULL)
       return root;
    if(LEFT==NULL && RIGHT==NULL)
        return NULL;
    if(LEFT!=NULL)
        return lca(root->left, n1, n2);
        
    return lca(root->right, n1, n2);
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
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    cout<<endl;
    Node* temp=BT.lca(root, 60,50);
    cout<<"LCA of the two nodes is: "<<temp->data<<endl;
}
