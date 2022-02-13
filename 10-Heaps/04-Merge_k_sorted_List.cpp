
// Min Heap: Merge k-Sorted List
//https://leetcode.com/problems/merge-k-sorted-lists/

/*
 Input: lists = [[1,4,5],[1,3,4],[2,6]]
 Output: [1,1,2,3,4,4,5,6]
 */

#include<iostream>
#include<vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

class Solution {
    struct node {
        Node *head;    //headent node
        int idx;    //List index number
        node(Node *a,int b)
        {
            head = a;
            idx = b;
        }
    };
    struct compare {
    bool operator()(node a, node b)
    {
        return a.head->data >b.head->data;
    }
};
public:
    Node* mergeKLists(vector<Node*>& lists) {
        int k = lists.size();
        if(k==0)
            return NULL;
        Node *start,*end;
        start=end=NULL;
        priority_queue<node,vector<node>,compare> heap;
        vector<Node*> ptr(k);   //headent node ptrs for all the lists
        //Assign all the headent ptrs and BUILD_HEAP
        for(int i=0;i<k;++i)
        {
            ptr[i]=lists[i];
            if(ptr[i]!=NULL)
                heap.push(node(ptr[i],i));
        }
        
        if(heap.empty())
            return NULL;
        //Insert 1st node
        start=end=heap.top().head;
        int idx = heap.top().idx;
        heap.pop();
        ptr[idx]=ptr[idx]->next;
        if(ptr[idx])    //Push newly pointed node if not NULL
            heap.push(node(ptr[idx],idx));
        
        //Make list with rest of the nodes
        while(!heap.empty())
        {
            Node *temp=heap.top().head; //Pop root node
            idx=heap.top().idx;
            heap.pop();
            
            end->next=temp;    //Add newnode to list
            end=end->next;
            ptr[idx]=ptr[idx]->next;    //Update current pointer
            if(ptr[idx])   //Push newly pointed node if not NULL
                heap.push(node(ptr[idx],idx));
        }
        return start;
    }
};

