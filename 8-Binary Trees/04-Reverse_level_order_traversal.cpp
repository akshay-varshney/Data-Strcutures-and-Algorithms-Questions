//Binary Tree: Reverse Level Order Traversal...



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
        int height(Node* root);
        void level_order_Traversal(Node *root, int H);
        void printCurrentLevel(Node* root, int level);
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
    else if(level>1){
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void Node::level_order_Traversal(Node* root, int H){
    for(int i=H;i>=1;i--)
    {
        printCurrentLevel(root, i);
    }
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
    int H=BT.height(root);
    cout<<"Level order Traversal: ";
    BT.level_order_Traversal(root, H);
    cout<<endl;
    return 0;
}
