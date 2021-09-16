// Array: Seprate all negative and positive numbers in an array

//https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

#include<iostream>

using namespace std;

// Seprate the numbers
int seprate(int arr[], int n){
    if (n<=0) return -1;
    if(n==1) return 0;
    int start=0, mid=n-1;
  
    while(start<=mid ){
        if(arr[start]>0 && arr[mid]>0){
            mid--;
        }
        else if(arr[start]<0 && arr[mid]<0){
            start++;
           
        }
        else if(arr[start]>0 && arr[mid]<0){
            swap(arr[start],arr[mid]);
            start++;
            mid--;
        }
        else{
            start++;
            mid--;
        }
    }
    return 0;
}

int main(){
    int arr[]={-1,2,3,4,-6,-4,-11,13};
    int n=sizeof(arr)/sizeof(arr[0]);
    seprate(arr, n);
    for(int i=0;i<n;i++){
        std::cout<<*(arr+i)<<" ";
    }
    std::cout<<std::endl;
}


