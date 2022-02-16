// Heap: k Most Frequent Elements in Array
//https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>


class Node{
private:
    int data;
    int freq;
public:
    Node(){};
    Node(int val1, int val2): data(val1) , freq(val2){}
    friend struct compare;
    std::vector<int> topKFrequentElement(std::vector<int>& A, int k);
};

// overloading operator and comparing the data of the nodes
struct compare{
    bool operator()(Node const&a, Node  const&b){
        return a.freq <b.freq;
    }
};

std::vector<int> Node::topKFrequentElement(std::vector<int> &A, int k){
    std::unordered_map<int, int> m1;
    // Storing the Frequency inside the map
    for(auto iter=A.begin(); iter!= A.end() ;iter++){
        std::unordered_map<int, int>::iterator it= m1.find(*iter);
        if(it!=m1.end()){
            it->second++;
        }
        else{
            m1.insert(std::make_pair(*iter, 1));
        }
    }
    // Heap that will give the top most frequent elements
    std::priority_queue<Node, std::vector<Node>, compare> heap;
    for(auto iter=m1.begin(); iter!= m1.end(); iter++){
        heap.push(Node(iter->first, iter->second));
    }
    std::vector<int> ans;
    while(k>0){
        Node temp= heap.top();
        heap.pop();
        ans.push_back(temp.data);
        k--;
    }
    return ans;
}

void Print(std::vector<int> &A, int n){
    for(int i=0; i<n; i++){
        std::cout<< A[i] <<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> A = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = A.size();
    std::cout<<"Max Heap1 is: ";
    Print(A, n);
    int k=2;
    Node H1;
    std::vector<int> V2= H1.topKFrequentElement(A, k);
    std::cout<<"K most Frequent Elements: ";
    for(auto it=V2.begin(); it!=V2.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}


