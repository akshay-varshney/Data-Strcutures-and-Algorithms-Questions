#include <iostream>

using namespace std;


void merge(int* A, int* L, int left_length, int* R, int right_length) {
    int l = 0;
    int r = 0;
    int i=0;
    while(l<left_length && r<right_length){
        if(L[l]<=R[r]){
            A[i]=L[l];
            l++;
        }
        else{
            A[i]=R[r];
            r++;
        }
        i++;
    }
    while(l<left_length){
        A[i]=L[l];
        l++;
        i++;
    }
    while(r<right_length){
        A[i]=R[r];
        r++;
        i++;
    }
}

void merge_sort(int* A, int length) {
    if (length == 1)return;
    int mid = length / 2;
    int* L = new int[mid];
    int* R = new int[length - mid];
    int k = 0;

    for (size_t i = 0; k < mid; i++){
        L[i] = A[k++];
    }
    for (size_t i = 0; k < length; i++){
        R[i] = A[k++];
    }

    merge_sort(L, mid);
    merge_sort(R, length - mid);

    merge(A, L, mid, R, length - mid);
    delete(L);
    delete(R);
}
int main() {

    int A[] = { 1,3,4,7,2,8,5,6,9 };

    int size = sizeof(A) / sizeof(A[0]);

    merge_sort(A, size);

    for (size_t i = 0; i < size; i++)cout<<A[i]<<" ";

}
