//Binary Search Tree: Delete Node in a BST

//https://leetcode.com/problems/delete-node-in-a-bst/submissions/

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
    Node* _delete(Node* root, int key);
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

Node* Node::findMini(Node *root){
    while(root->left !=NULL){
        root=root->left;
    }
    return root;
}

Node* Node::_delete(Node *root, int key)
{
    if(root==NULL){
        return root;
    }
    else if(key< root->data)
        root->left= _delete(root->left, key);
    else if(key> root->data)
        root->right= _delete(root->right, key);
    
    else{
        // when deleted node has no child in that just set root NULL
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        // if it has no left child then make the first right as root
        else if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        // if it has no right child then make the first left as the root node
        else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        // 2 Sub tree case, find the minimum value from the right sub tree and then call the delete function again with the root->right
        else{
            Node *temp= findMini(root->right);
            root->data=temp->data;
            root->right=_delete(root->right, temp->data);
        }
    }
    return root;
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
    BT._delete(root, 120);
    cout<<"Inorder Traversal of Tree After Deletion: ";

    BT.inorder(root);
    cout<<endl;
}
