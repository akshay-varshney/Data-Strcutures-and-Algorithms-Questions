// Array: Maximum and minimum of an array using minimum number of comparisons
// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/


#include <iostream>

// Method 1: Linear Search: Total Number of comparision in this is : n

int _linear(int arr[], int n){
    if (n<=0){
        return -1;
    }
    int maxi=arr[0];
    int mini=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    std::cout<<"Maximum: "<<maxi<<std::endl;
    std::cout<<"Minimum: "<<mini<<std::endl;
    return 0;
}

// Method2: Pair wise comparision:
/*
 If n=even then total comparision:1 + 3*(n-2)/2
 If n=odd then total comparision:1 + 3*(n-1)/2
 */
int compare_pairs(int arr[], int n){
    if (n<=0){
        return -1;
    }
    if(n==1){
        std::cout<<"Maximum: "<<arr[0]<<std::endl;
        std::cout<<"Minimum: "<<arr[0]<<std::endl;
    }
    size_t maxi, mini;
    int i=0;
    if(n%2==0){
        if(arr[0]>arr[1]){
            maxi=arr[0];
            mini=arr[1];
        }
        else{
            maxi=arr[1];
            mini=arr[0];
        }
        i+=2;
    }
    else{
        maxi=arr[0];
        mini=arr[0];
        i++;
    }
    
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
            if(arr[i+1]<mini){
                mini=arr[i+1];
            }
        }
        
        else{
            if(arr[i+1]>maxi){
                maxi=arr[i+1];
            }
            if(arr[i]<mini){
                mini=arr[i];
            }
        }
        i+=2;
    }
    std::cout<<"Maximum: "<<maxi<<std::endl;
    std::cout<<"Minimum: "<<mini<<std::endl;
    
    return 0;
}



int main(){
    int arr[] = {11,22,3,42,5,61,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    _linear(arr, n);
    compare_pairs(arr, n);
    return 0;
}
