//Binary Tree: Insertion of elements in Binary Tree.
// https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/

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
        void print_Node(Node *root);
    
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

Node* Node::InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL){
            temp->left = CreateNode(data);
            return root;
        }
        else {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = CreateNode(data);
            return root;

        }
        else {
            q.push(temp->right);
        }
    }
    return root;
}

void Node::print_Node(Node *temp)
{
    if (temp == NULL)
        return;

    print_Node(temp->left);
    cout << temp->data << " ";
    print_Node(temp->right);
}


int main()
{
    /*
          Binary Tree
             1
            /   \
           2     3
         /      /  \
        4      5    6
        
          */
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->left->left = BT.CreateNode(3);
    root->right = BT.CreateNode(4);
    root->right->left = BT.CreateNode(5);
    root->right->right = BT.CreateNode(6);
    cout<<"Tree :";
    BT.print_Node(root);
    cout << endl;
    root = BT.InsertNode(root, 7);
    cout<<"InsertionNode :";
    BT.print_Node(root);
    cout << endl;
    return 0;
}
