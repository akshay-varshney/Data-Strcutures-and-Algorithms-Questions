// Detect a Cycle using Disjoint Set: Find Union, Path Compression and Rank concept

#include<iostream>
#include<vector>
using namespace std;

struct node {
    int parent;
    int rank;
};

vector<node> disjoint;

int find(int v)
{
    if(disjoint[v].parent==-1)
        return v;
    return disjoint[v].parent=find(disjoint[v].parent);    //Path Compression
}

void union_op(int first,int second)
{
    // if rank is different then we'll not change the rank
    if(disjoint[first].rank > disjoint[second].rank)    //first has higher rank
        disjoint[second].parent = first;
    else if(disjoint[first].rank < disjoint[second].rank)    //second has higher rank
        disjoint[first].parent = second;
    else
    {
        //Both have same rank and so anyone can be made as parent
        disjoint[first].parent = second;
        disjoint[second].rank +=1;        //Increase rank of parent
    }
}

bool isCyclic(vector<pair<int,int>>& edge_List)
{
    for(auto it= edge_List.begin(); it!=edge_List.end(); it++)
    {
        int first = find(it->first);    //FIND absolute parent of subset
        int second = find(it->second);

        if(first == second)
            return true;

        //UNION operation
        union_op(first,second);    //UNION of 2 sets
    }
    return false;
}
