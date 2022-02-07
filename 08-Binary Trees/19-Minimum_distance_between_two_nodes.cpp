//Binary Tree: Min distance between two given nodes of a Binary Tree

//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#


#include <iostream>


using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    Node* lca(Node* root ,int n1 ,int n2 );
    int distancebtwnNodes(Node* root, int n1, int n2);
    int findDistance(Node *lca, int k, int dist);
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

// LCA of the two nodes.
Node* Node::lca(Node* root ,int n1 ,int n2 )
{

    if(root->data==n1 || root->data==n2)
    {
           return root;
    }
    
    if(root==NULL)
    {
        return NULL;
    }
    
   Node *LEFT=NULL;
   Node * RIGHT=NULL;
    
   if(root->left)
   {
       LEFT=lca(root->left, n1, n2);
   }
   if(root->right)
   {
       RIGHT= lca(root->right, n1, n2);
   }
   if(LEFT!=NULL && RIGHT!=NULL)
   {
       return root;
    }
    if(LEFT==NULL && RIGHT==NULL){
        return NULL;
    }
    if(LEFT!=NULL){
        return lca(root->left, n1, n2);
    }
    
    return lca(root->right, n1, n2);
}

int Node::findDistance(Node *lca, int k, int dist){
    if(lca==NULL){
        return -1;
    }
    if(lca->data==k){
        return dist;
    }
    int left=findDistance(lca->left, k, dist+1);
    if(left !=-1){
        return left;
    }
    return findDistance(lca->right, k, dist+1);
}

int Node::distancebtwnNodes(Node* root, int n1, int n2)
{
    Node *LCA=lca(root, n1, n2);
    int d1=findDistance(LCA, n1, 0);
    int d2= findDistance(LCA, n2, 0);
    return d1+d2;
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
    cout<<"Minimum Diatance between Nodes: "<<BT.distancebtwnNodes(root, 2, 3)<<endl;
}
