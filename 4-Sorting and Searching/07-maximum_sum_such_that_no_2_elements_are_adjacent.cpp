// Searching & Sorting: maximum sum such that no 2 elements are adjacent

/*
 a[] = {5,5,10,100,10,5}
 Output: 110
 Explanation: 5+100+5=110
 */
#include<iostream>
#include<vector>
using namespace std;

// Taking two pointers include will take the current element included in the maximum sum so far while exclude will not take the current element in the maximum sum so far
int maximum_sum(vector<int> &arr){
    int n=arr.size();
    int include = arr[0];
        int exclude = 0;
        int exclude_new;
        int i;

        for (i = 1; i < n; i++)
        {
            exclude_new = max(include,exclude);
            include = exclude + arr[i];
            exclude = exclude_new;
        }

       
        return max(include,exclude);
}


int main(){
    vector<int> v1= {1,21,200,4,8,61,7};
    cout<<maximum_sum(v1)<<endl;    
}
