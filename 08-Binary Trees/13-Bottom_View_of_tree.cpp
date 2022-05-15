//Binary Tree: Bottom View of the Tree.

//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#


#include <iostream>
#include <queue>
#include <vector>
#include <map>


using namespace std;

class Node {
    
    public:
        int data;
        Node* left;
        Node* right;
        Node *CreateNode(int data);
        Node *InsertNode(Node* root, int data);
        vector<int> bottomView(Node* root);
    void printBottomViewMethod2(Node * root, int curr, int hd, map <int, pair <int, int>> & m);
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

vector<int> Node::bottomView(Node *root)
{
    vector<int> ans={};
    queue<pair<Node *, int>> Q1;
    if(root==NULL){
        return ans;
    }
    map<int, int> M1;
    Q1.push(std::make_pair(root, 0));
    while(!Q1.empty()){
        auto iter=Q1.front();
        Q1.pop();
        auto it = M1.find(iter.second);
        if(it!=M1.end())
            it->second = (iter.first)->data;
        else
            M1.insert(std::make_pair(iter.second, (iter.first)->data));
        
        if(iter.first->left!=NULL)
            Q1.push(std::make_pair(iter.first->left, iter.second-1));
        
        if(iter.first->right!=NULL)
            Q1.push(std::make_pair(iter.first->right, iter.second+1));
        
    }
    for(auto it=M1.begin(); it!=M1.end(); it++)
        ans.push_back(it->second);
    
    return ans;
}


void printBottomViewMethod2(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    // Base case
    if (root == NULL)
        return;
     
    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
     
    // Recur for left subtree
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
     
    // Recur for right subtree
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
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
    vector<int>V2= BT.bottomView(root);
    cout<<"Bottom View of the Tree: ";
    for(auto it=V2.begin();it!=V2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
