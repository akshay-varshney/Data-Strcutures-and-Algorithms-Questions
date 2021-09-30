// Array: Trapping Rain Water
// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
#include<iostream>
#include<vector>

using namespace std;
// By this method we are capturing the maximum left and maximum right value for an element and store them in array
int water_stored(vector<int> &A){
    double water_stored=0;
    int n=A.size();
    if(n<=2) return water_stored;
    vector<int> max_r(n);
    vector<int> max_l(n);
    max_l[0]=0;
    int left_max=A[0];
    for(int i=1;i<n;i++){
        max_l[i]=left_max;
        left_max=max(left_max,A[i]);
    }
    max_r[n-1]=0;
    int right_max=A[n-1];
    for(int i=n-2;i>=0;i--){
        max_r[i]=right_max;
        right_max=max(right_max,A[i]);
    }
    for(int i=1;i<n-1;i++){
        if(A[i]<max_l[i] && A[i]<max_r[i]){
        water_stored+=(min(max_l[i],max_r[i])-A[i]);
        }
    }
    return water_stored;
}
//Time: O(n) and Space: O(n)


// Method2: Using Two pointer approach. Tracking the maximum left and maximum right value in a variable
// If left is greater than caculate area from left side and if right is greater than calcukate area from the right side...

int max_water_2(vector<int> &A){
    int n=A.size();
    int maxleft=A[0];
    int maxright=A[n-1];
    int start=1;
    int end=n-2;
    double water_stored=0;
    if(n<=2) return water_stored;
    while(start<end){
        if(maxleft<maxright){
            if(A[start]>=maxleft){
                maxleft=A[start];
            }
            else{
                water_stored+=maxleft-A[start];
            }
            start++;
        }
        else{
            if(A[end]>=maxright){
                maxright=A[end];
            }
            else{
                water_stored+=maxright-A[end];
            }
            end--;
        }
    }
    return water_stored;
}
// Time: O(n) and space: O(1)

int main(){
    vector<int> v1={8, 8, 2, 4, 5, 5, 1};
    cout<<water_stored(v1)<<endl;
    cout<<max_water_2(v1)<<endl;
}
