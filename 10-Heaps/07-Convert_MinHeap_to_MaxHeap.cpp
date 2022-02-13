// Heap: Convert Min Heap to Max Heap
//https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/

#include<iostream>
#include<vector>

using namespace std;

void MaxHeapify(vector<int> &A, int i, int n)
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
        swap(A[i], A[largest]);
        MaxHeapify(A, largest, n);
    }
}

void convertmintomaxHeap(vector<int> &A, int n){
    int start= (n/2)-1;
    for(int i=start; i>=0;i--){
        MaxHeapify(A, i, n);
    }
}

void Print(vector<int> &A, int n){
    for(int i=0; i<n; i++){
        cout<< A[i] <<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> A = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = A.size();
    cout<<"Min Heap is: ";
    Print(A, n);
    convertmintomaxHeap(A, n);
    cout<<"Max Heap is: ";
    Print(A, n);
}
