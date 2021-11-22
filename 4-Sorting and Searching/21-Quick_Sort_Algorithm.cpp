// Searching and Sorting: Quick Sort Algorithm

#include <iostream>

using namespace std;

int partition(int *A, int start, int end){
    int i=start;
    int pindex=start;
    int pivot=A[end];
    while(i<end){
        if(A[i]<=pivot){
            swap(A[i], A[pindex]);
            pindex++;
        }
        i++;
    }
    swap(A[pindex],A[end]);
    return pindex;
}

void quicksort(int *A, int start, int end){
    if(start<end){
        int pindex=partition(A,start, end);
        quicksort(A,start,pindex-1);
        quicksort(A, pindex+1, end);
    }
    
}
// Time: O(nlogn) and Space: O(1)

int main() {

    int A[] = { 1,3,4,7,2,8,5,6,9 };
    int size = sizeof(A) / sizeof(A[0]);
    quicksort(A, 0, size);
    for (size_t i = 0; i < size; i++){
        cout<<A[i]<<" ";
    }
}
