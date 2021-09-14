//Array: Sort an array of 0,1,2
//Q. https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include<iostream>

using namespace std;

// Method 1: By counting all the 0,1,2.
// Time Complexity: O(n) and Space Complexity: O(1)

int *separate_1(int arr[], int n){
    int x=0, y=0,z=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) x++;
        else if(arr[i]==1) y++;
        else z++;
    }
    int i=0;
    while(x>0){
        arr[i]=0;
        i++;
        x--;
    }
    while(y>0){
        arr[i]=1;
        i++;
        y--;
    }
    while(z>0){
        arr[i]=2;
        i++;
        z--;
    }
    return arr;
}

// Method 2 dividing array into three parts using threee variables.
// Time Complexity: O(n) and Space Complexity: O(1)
int *_seprate_opt(int arr1[], int n){
    if (n<=0) return nullptr;
    if (n==1) return arr1;
    int start=0;
    int end=n-1;
    int mid=0;
    while(mid<=end){
        if(arr1[mid]==0){
            swap(arr1[start], arr1[mid]);
            mid++;
            start++;
        }
        else if (arr1[mid]==1) mid++;
        else if(arr1[mid]==2){
            swap(arr1[mid], arr1[end]);
            end--;
        }
    }
    return arr1;
}

int main() {
    int arr[]={0,2,1,2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int *ptr=separate_1(arr, n); // Method 1
    
    // Printing the array as it returning the reference
    for(int i=0;i<n;i++){
        std::cout<<*(ptr+i)<<" ";
    }
    std::cout<<std::endl;
    int arr1[]={0,2,1,2,0,1,2,0};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int *ptr2=_seprate_opt(arr1, n1); // Method 2
    for(int i=0;i<n1;i++){
        std::cout<<*(ptr2+i)<<" ";
    }
    std::cout<<std::endl;
}
