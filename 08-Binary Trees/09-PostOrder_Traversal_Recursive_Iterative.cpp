//Binary Tree: PostOrder traversal of Tree using Iterative and Recursive way
// Postorder (Left, Right, Root) : 4 5 2 3 1


#include <iostream>
#include <stack>
using namespace std;

class Node {
    
    public:
        int data;
        Node* left;
        Node* right;
        Node *CreateNode(int data);
        Node *InsertNode(Node* root, int data);
        void postorder(Node* root);
        void recursive_Postorder(Node* root);
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
void Node::postorder(Node* root)
{
    if (root == NULL)
        return;
   
    postorder(root->left);
    postorder(root->right);
    cout <<" "<< root->data;
}

// using two stack and keep pushing element to second stack if the left and right child of the node is not NULL
// After that reversing the second stack
void Node::recursive_Postorder(Node *root){
    if(root==NULL){
        return;
    }
    stack<Node*> S1;
    stack<int> S2;
    Node* temp=root;
    S1.push(root);
    while (!S1.empty()) {
        temp=S1.top();
        S1.pop();
        S2.push(temp->data);
        if(temp->left){
            S1.push(temp->left);
        }
        if(temp->right){
            S1.push(temp->right);
        }
        
    }
    while(!S2.empty()){
        cout<<S2.top()<<" ";
        S2.pop();
    }
}


int main()
{
    /*
        Binary Tree
           1
          /   \
         2     3
       /   \  /  \
      4    5  6   7
                \
                 8
        */
    
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->left->right = BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right = BT.CreateNode(7);
    root->right->left->right = BT.CreateNode(8);
    cout <<"PostOrder Traversal of tree: ";
    BT.postorder(root);
    cout<<endl;
    cout<<"Recursive PostOrder Traversal: "<<endl;
    BT.recursive_Postorder(root);
    cout<<endl;
}
