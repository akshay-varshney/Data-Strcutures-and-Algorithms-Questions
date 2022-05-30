// Array: Wave Array
// https://www.interviewbit.com/problems/wave-array/
/*
 Input: A = [1, 2, 3, 4]
 O/p: [2, 1, 4, 3]
 */
#include<iostream>
#include<vector>


using namespace std;

vector<int> wave(vector<int> &A){
    int n=A.size();
    sort(A.begin(),A.end());
    vector<int> ans;
    int i=0;
    while(i<n-1){
        swap(A[i],A[i+1]);
        ans.push_back(A[i]);
        ans.push_back(A[i+1]);
        i+=2;
    }
    if(i<n){
        ans.push_back(A[i]);
    }
    return ans;
}

// Method 2:
void sortInWave(vector<int> & arr, int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if (i>0 && arr[i-1] > arr[i] )
            swap(arr[i], arr[i-1]);
 
        // If current even element is smaller than next
        if (i<n-1 && arr[i] < arr[i+1] )
            swap(arr[i], arr[i + 1]);
    }
}
 
//Time: O(nlogn) and Space:O(n)

int main(){
    vector<int> v1={6,4,3,1,2};
    vector<int> v2;
    v2=wave(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
}
