//Binary Tree: Check if two binary Trees are mirror of each other.

#include <iostream>


using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    void inorder(Node* root);
    void mirror(Node* root1, Node* root2);
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


bool flag=true;
void Node::mirror(Node* root1, Node* root2){
    if(root1==NULL || root2==NULL){
        return;
    }
    
    mirror(root1->left, root2->right);
    mirror(root1->right, root2->left);
    if(root2->data!=root1->data){
        cout<<endl;
        cout<<"Not a Mirror"<<endl;
        flag=false;
        return;
    }
}

void Node::inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout <<" "<< root->data;
    inorder(root->right);
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
    
    Node* root1 = BT.CreateNode(1);
    root1->left = BT.CreateNode(3);
    root1->right = BT.CreateNode(2);
    root1->left->left = BT.CreateNode(7);
    root1->left->right= BT.CreateNode(6);
    root1->right->left=BT.CreateNode(5);
    root1->right->right=BT.CreateNode(4);
    cout<<"Inorder Traversal of Tree: ";
    BT.inorder(root);
    BT.mirror(root, root1);
    if(flag){
        cout<<endl;
        cout<<"Both Trees are mirror of each other"<<endl;
    }
}
