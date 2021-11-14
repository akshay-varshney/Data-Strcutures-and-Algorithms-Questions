// Searching & Sorting: Merge Without Extra Space 

#include<iostream>
#include<vector>
using namespace std;
// Method1: Linear Search while keep on sorting the second array after each iteration if the swap has been happened

// Method 2: by comparing the element from back of the second array with first array
void merge_two_sorted(vector<int> &A, vector<int> &B){
    int n=A.size();
    int m=B.size();
    for(int i=m-1;i>=0;i--){
        int j=n-2;
        int last=A[n-1];
        while(j>=0 && A[j]>B[i]){
            A[j+1]=A[j];
            j--;
        }
        if(j!=n-2 || last>B[i]){
            A[j+1]=B[i];
            B[i]=last;
        }
    }
}

// Time: O(m*n)

// Method 3: By using gap method
void gap_method(vector<int> &A, vector<int> &B){
    int n=A.size();
    int m=B.size();
    int gap=(m+n);
    if(gap<=1){
        gap=0;
    }
    else{
        gap=(gap/2)+gap%2;
    }
    while(gap>0){
        int i,j=gap-n;
        for(i=0;i+gap<n;i++){
            if(A[i]>A[i+gap]){
                swap(A[i],A[i+gap]);
            }
        }
        if(gap>n){
            j=gap-n;
        }
        else{
            j=0;
            
        }
        while(i<n && j<m){
            int val=j-n;
            if(A[i]>B[j]){
                swap(A[i],B[j]);
            }
        }
        while(j<m){
            if(A[j]>A[j+gap]){
                swap(B[j],B[j+gap]);
            }
        }
        if(gap<=1){
            gap=0;
        }
        else{
            gap=(gap/2)+gap%2;
        }
    }
}
// Time: O(m+n)

int main(){
    vector<int> v1= {1, 3, 5, 7};
    vector<int> v2={0, 2, 6, 8, 9};
//    merge_two_sorted(v1, v2);
    gap_method(v1, v2);
    for(auto it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
}
