// Heap: Max heap Implementation (Heapify)

#include<iostream>

using namespace std;

//
//Parent=i
//leftchild= 2*i+1
//rightchild= 2*i+2


void heapify(int arr[], int n, int i){
    int largest=i;
    int left= 2*i+1;
    int right= 2*i+2;
    // Find the largest from the left
    if(left< n && arr[left] > arr[largest]){
        largest=left;
    }
    // finding the largest from the right
    if(right<n && arr[right]> arr[largest]){
        largest=right;
    }
    // if we found the largest then swap the elements and call the heapify property recrsively.
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    int start= (n/2)-1;
    //Perform reverse level order traversal from last non-leaf node and heapify each node
    for(int i=start; i>=0;i--){
        heapify(arr, n, i);
    }
}

void Print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}

int main()
{
    /*
     Binary Tree Representation as an array
                 1
               /    \
             3        4
           /  \     /  \
         14      15  16    7
    */
    int arr[] = { 1, 3, 4, 14, 15, 16, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<" Array is ";
    Print(arr, n);
    cout<<endl;
    buildHeap(arr, n);
    cout<<"Max Heap is ";
    Print(arr, n);
    cout<<endl;
/*
    Heap is:
                  16
                /    \
              15      7
             /  \    /  \
            14    3  4    1
  
 */
}
