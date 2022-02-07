// Searching & Sorting: Smallest factorial number
//https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#
/*
 Input:
 n = 6
 Output: 25
 */
#include<iostream>
#include<vector>

using namespace std;

/// Calculatiung all the trailing zero by counting all the 5 in an number
// formula: (n/5)+(n/25) +(n/125)....

bool check_count(int n, int p){
    int count=0;
    int k=1;
    while((n/pow(5,k))>=1){
//        cout<<(n/pow(5,k))<<endl;
        count+=floor(n/pow(5,k));
        k++;
    }
    if(count<p){
        return false;
    }
    return true;
}
// using binary search to find the minimum value
int findNum(int n){
   if(n==1){
       return 5;
   }
   int low=0;
   int high=5*n;
   while(low<high){
       int mid=(low+high)/2;
       if(check_count(mid,n)){
           high=mid;
       }
       else{
           low=mid+1;
       }
   }
   return low;
}

int main(){
    int n=84;
    cout<<findNum(n)<<endl;
 
}
