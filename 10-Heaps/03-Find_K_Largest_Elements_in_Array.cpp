// Heap: Smallest/Largest k Elements in Array

//https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include<iostream>
#include<vector>

using namespace std;


// Min heap is used when we need to find the largest k numbers

void heapify(vector<int> &A, int n, int current)
{
    
    int smallest=current;
    int left= 2*current+1;
    int right= 2*current+2;
    
    if(left< n && A[left] < A[smallest])
        smallest=left;
    
    if(right<n && A[right]< A[smallest])
        smallest=right;

    if(smallest != current)
    {
        swap(A[current], A[smallest]);
        heapify(A, n, smallest);
    }
}

// Creating another vector which will store exactly k element and everytime we will heapify k elements in the vector.
void FirstKelements(vector<int> &A,int n,int k){
    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(A[i]);
        heapify(ans, ans.size(), 0);
        if(ans.size() > k){
            ans.erase(ans.begin());
        }
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    ans.clear();
}

void Print(vector<int> &A, int n){
    for(int i=0; i<n; i++){
        cout<< A[i] <<" ";
    }
    cout<<endl;
}

int main()
{
    /*
     Binary Tree Representation as an Aay
                 1
               /    \
             3        4
           /  \     /  \
         14      15  16    7
    */
    vector<int> A = { 1, 3, 4, 14, 15, 16, 7};
    cout<<"Array is ";
    Print(A, A.size());
    cout<<endl;
    cout<<"Largest k Elements in Array is: ";
    FirstKelements(A, A.size(), 4);
    cout<<endl;
}
