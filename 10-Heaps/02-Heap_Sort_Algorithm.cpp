// Heap: Heap Sort Algorithm
// https://www.geeksforgeeks.org/heap-sort/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &A, int n, int current){
    int largest=current;
    int left= 2*current+1;
    int right= 2*current+2;
    if(left< n && A[left] > A[largest])
        largest=left;
    
    if(right<n && A[right]> A[largest])
        largest=right;

    if(largest != current)
    {
        swap(A[current], A[largest]);
        heapify(A, n, largest);
    }
}

void buildHeap(vector<int> &A, int n){
    int start= (n/2)-1;
    for(int i=start; i>=0;i--){
        heapify(A, n, i);
    }
}

void heapSort(vector<int> &A, int n) {
    buildHeap(A, n);
    for(int i=n-1; i>0;i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
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
    /*
     Binary Tree Representation as an Aay
                 1
               /    \
             3        4
           /  \     /  \
         14      15  16    7
    */
    vector<int> A = { 1, 3, 4, 14, 15, 16, 7};
    int n = sizeof(A) / sizeof(A[0]);
    cout<<"Array is ";
    Print(A, n);
    cout<<endl;
    heapSort(A, n);
    cout<<"Sorted Array is ";
    Print(A, n);
/*
    Heap is:
                  16
                /    \
              15      7
             /  \    /  \
            14    3  4    1
  
 */
}
