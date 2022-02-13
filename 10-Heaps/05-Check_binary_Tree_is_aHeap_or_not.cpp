// Heap: Check if a binary tree is a heap or not.

/*
 For a Binary Tree to be it must satisfy 2 perpoerties:
 1. It must be a complete Binary Tree.
 2. All the nodes in left and right must have value less than root.
 */
#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *newNode(int k);

};


Node* Node::newNode(int k)
{
    struct Node *node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}

//Counting number of nodes in a Binary Tree.
 int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

/* This function checks if the
binary tree is complete or not */
bool isComplete (struct Node* root,
                     int index,
                     int number_nodes)
{
 
    if (root == NULL)
        return (true);

    // If index assigned to
    // current node is more than
    // number of nodes in tree,
    // then tree is not complete
    if (index >= number_nodes)
        return (false);

    // Recur for left and right subtrees
    return (isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes));
}

// This Function checks the
// heap property in the tree.
bool compareHeapData(struct Node* root)
{

    if (root->left == NULL && root->right == NULL)
        return (true);

    // node will be in
    // second last level
    if (root->right == NULL)
    {
        // check heap property at Node
        // No recursive call ,
        // because no need to check last level
        return (root->data >= root->left->data);
    }
    else
    {
        // Check heap property at Node and
        // Recursive check heap
        // property at left and right subtree
        if (root->data >= root->left->data && root->data >= root->right->data)
            return ((compareHeapData(root->left)) && (compareHeapData(root->right)));
        else
            return (false);
    }
}

// Function to check binary
// tree is a Heap or Not.
bool isHeap(struct Node* root)
{
     int node_count = countNodes(root);
     int index = 0;

    if (isComplete(root, index, node_count) && compareHeapData(root))
        return true;
    
    return false;
}


int main()
{
    Node BT;
    Node* root = NULL;
    root = BT.newNode(10);
    root->left = BT.newNode(9);
    root->right = BT.newNode(8);
    root->left->left = BT.newNode(7);
    root->left->right = BT.newNode(6);
    root->right->left = BT.newNode(5);
    root->right->right = BT.newNode(4);
    root->left->left->left = BT.newNode(3);
    root->left->left->right = BT.newNode(2);
    root->left->right->left = BT.newNode(1);

    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    
    /*
           Binary Tree
              1
             /   \
            2     3
          /   \  /  \
         4    5  6   7
          
           */
       
       Node BT2;
       Node* root2 = BT2.newNode(1);
       root2->left = BT2.newNode(2);
       root2->right = BT2.newNode(3);
       root2->left->right = BT2.newNode(4);
       root2->left->right->right = BT2.newNode(5);
       root2->left->right->right->right=BT2.newNode(6);
    if (isHeap(root2))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
    
    
}

