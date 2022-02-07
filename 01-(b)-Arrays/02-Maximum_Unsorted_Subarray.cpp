// Array: Maximum Unsorted Subarray
// https://www.interviewbit.com/problems/maximum-unsorted-subarray/
/*
 A = [1, 3, 2, 4, 5]

 Return: [1, 2]
 */
#include<iostream>
#include<vector>

using namespace std;


//finding the start and end indexes of the array amd then checking in left start and then checking in right of end if there is any index greater in left of start and if there is any index smaaler than left of end
vector<int> sub_unsort(vector<int> &A){
    int n=A.size();
        int start=INT_MAX;
        int end=INT_MIN;
        vector<int> ans(2);
        ans[0]=start;
        ans[1]=end;
        int j=0;
        int count=1;
        for(int i=1;i<n;i++){
            if(A[i]>=A[j]){
                j++;
                count++;
            }
            else{
                start=j;
                break;
            }
        }
        if(count==n){
            ans.pop_back();
            ans[0]=-1;
            return ans;
        }
        int i=n-1;
        while(i>start){
            if(A[i]<A[i-1]){
                end=i;
                break;
            }
            i--;
        }
        int min_value=INT_MAX;
        int max_value=INT_MIN;
        for(int i=start;i<=end;i++){
            min_value=min(min_value,A[i]);
            max_value=max(max_value,A[i]);
        }
        for(int i=0;i<start;i++){
            if(A[i]>min_value){
                start=i;
                break;
            }
        }
        for(int i=n-1;i>end;i--){
            if(A[i]<max_value){
                end=i;
                break;
            }
        }
        ans[0]=start;
        ans[1]=end;
        return ans;
}


int main(){
    vector<int> v1={1,3,2,4,5};
    vector<int> v2;
    v2=sub_unsort(v1);
    for(auto it=v2.begin(); it!=v2.end();it++){
        cout<<*it<<" ";
    }
}
