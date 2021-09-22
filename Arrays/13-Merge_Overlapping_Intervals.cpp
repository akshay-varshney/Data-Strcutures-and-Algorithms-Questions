// Array: Merge Overlapping Intervals
// https://leetcode.com/problems/merge-intervals/

#include<vector>
#include<iostream>

using namespace std;

// The total Time complexity is O(nlogn) and space complexity is O(n)
vector<vector<int>> merge_overlap(vector<vector<int>>& values){
    int n=values.size();
    // Sort the vector
    sort(values.begin(),values.end());
    vector<vector<int>> final;
    int start=0, end=0;
    start=values[0][0];
    end=values[0][1];
    // comparing the end of current with the start of the next if end becomes greater than replace end otherwise push back in answer and change start and end values to current value
    
    for(int i=1;i<n;i++){
        if(end>=values[i][0]){
            end=max(end,values[i][1]);
        }
        else{
            final.push_back({start,end});
            start=values[i][0];
            end=values[i][1];
        }
    }
    final.push_back({start,end});
    return final;
}

int main(){
    vector<vector<int>> v1={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans= merge_overlap(v1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}
