//Array: Max Non Negative SubArray
// https://www.interviewbit.com/problems/max-non-negative-subarray/

#include<iostream>
#include<vector>

using namespace std;

vector<int> maximu_subarray(int arr[], int n){
    int start=0, mid=0,val1=0,val2=0;
    double ans=-1;
  double su=0;
    while(mid<n){
        if(arr[mid]>=0){
            su+=arr[mid];
            mid++;
        }
        else if(arr[mid]<0){
            if(su>=ans){
                val1=start;
                val2=mid;
                ans=su;
            }
            start=mid+1;
            mid+=1;
            su=0;
        }
    }
    if(su>ans){
        val1=start;
        val2=mid;
    }
    vector<int> v1;
    for(int i=val1;i<val2;i++){
        v1.push_back(arr[i]);
    }
    return v1;
}

int main(){
    int arr[] = {1, 2, 5, -7, 2, 3 };
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v2;
    v2=maximu_subarray(arr, n);
    for(auto it:v2){
        cout<<it<<endl;
    }
}
