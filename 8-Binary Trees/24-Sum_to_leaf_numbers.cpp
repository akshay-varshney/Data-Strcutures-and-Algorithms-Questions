//Binary Tree: Sum Root to Leaf Numbers

//https://leetcode.com/problems/sum-root-to-leaf-numbers/

/*
 Input: root = [1,2,3]
 Output: 25
 Explanation:
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 Therefore, sum = 12 + 13 = 25.
 */
#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    void stringsum(Node* root, int summed);
    int sumNumbers(Node* root);
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


int ans=0;

void Node::stringsum(Node* root, int summed){
c    if(root==NULL){
        return;
    }
    
    summed*=10;
    summed+=root->data;
    if(root->left==NULL && root->right==NULL){
        ans+=summed;
        return;
    }
    stringsum(root->left, summed);
    stringsum(root->right, summed);
}

int Node::sumNumbers(Node* root) {
    
    if(root==NULL){
        return 0;
    }
    int summed=0;
    stringsum(root, summed);
    return ans;

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
    cout<<"The given sum of Tree is : ";
    cout<<BT.sumNumbers(root);
    cout<<endl;
}
