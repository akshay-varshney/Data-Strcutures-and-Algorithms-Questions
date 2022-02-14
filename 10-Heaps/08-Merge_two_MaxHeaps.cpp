// Heap: Merge two Binary Max Heaps
//https://www.geeksforgeeks.org/merge-two-binary-max-heaps/

#include<iostream>
#include<vector>

using namespace std;

void MaxHeapify(std::vector<int> &A, int i, int n)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && A[l] > A[i])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(A[i], A[largest]);
        MaxHeapify(A, largest, n);
    }
}

void Print(std::vector<int> &A, int n){
    for(int i=0; i<n; i++){
        std::cout<< A[i] <<" ";
    }
    std::cout<<std::endl;
}

std::vector<int> mergeHeaps(std::vector<int> &a, std::vector<int> &b, int n, int m)
{
    std::vector<int> ans;
    for(int i=0; i<n;i++){
        ans.push_back(a[i]);
    }
    for(int i=0; i<m;i++){
        ans.push_back(b[i]);
    }
    int start= ((m+n)/2)-1;
    for(int i=start; i>=0;i--){
        MaxHeapify(ans, i, m+n);
    }
    return ans;
}

int main()
{
    std::vector<int> A = { 10,5,6,2};
    int n = A.size();
    std::cout<<"Max Heap1 is: ";
    Print(A, n);
    std::vector<int> B = { 12,7,9};
    int m = B.size();
    std::cout<<"Max Heap2 is: ";
    Print(B, m);
    auto V2=mergeHeaps(A, B, n, m);
    std::cout<<"Merged Max Heap is: ";
    Print(V2, m+n);
}


