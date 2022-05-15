//Binary Tree: Diagonal View of the Tree.

//https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/


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
    void diagonalTraversal(Node * root);
    
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

void Node::diagonalTraversal(Node *root){
    queue<Node *> Q1;
    if(root==NULL)
        return;
    
    Q1.push(root);
    while(!Q1.empty()){
        int n= Q1.size();
        while(n>0)
        {
            Node * temp= Q1.front();
            Q1.pop();
            while (temp)
            {
                cout<<temp->data<<" ";
                if(temp->left){
                    Q1.push(temp->left);
                }
                temp=temp->right;
            }
            n--;
        }
        cout<<endl;
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
    
     */
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right=BT.CreateNode(7);
    cout<<"Diagonal View of the Tree: "<<endl;
    BT.diagonalTraversal(root);
    cout<<endl;

}
