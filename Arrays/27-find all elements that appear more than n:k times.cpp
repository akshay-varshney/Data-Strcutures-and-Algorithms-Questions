// Array: find all elements that appear more than n/k times
// https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
vector<int> occurence(vector<int> &arr, int k){
    unordered_map<int, int> m1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        unordered_map<int, int>::iterator iter1=m1.find(arr[i]);
        if(iter1!=m1.end()){
            iter1->second++;
        }
        else{
            m1.insert(std::make_pair(arr[i], 1));
        }
    }
    vector<int> ans;
    int val=n/k;
    for(auto it=m1.begin();it!=m1.end();it++){
        if((it->second)>val){
            ans.push_back(it->first);
        }
    }
    return ans;
}
//Time:O(n) and Space: O(n)

int main(){
    vector<int> v1={3, 1, 2, 2, 1, 2, 3, 3};
    int k=4;
    vector<int> v11;
    v11=occurence(v1,k);
    for(auto i=v11.begin();i!=v11.end();i++){
        cout<<*i<<" ";
    }
    
}
