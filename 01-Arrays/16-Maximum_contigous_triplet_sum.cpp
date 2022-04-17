// array: Maximum Sum triplet Contigous
//https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/
#include<vector>
#include<iostream>

using namespace std;

int max_triplet(vector<int> v1){
    int i=0;
    int n=v1.size();
    int j=i+2;
    int max_sum=INT_MIN;
    int _summ=0;
    if (n<3) return -1;
    _summ+=(v1[i]+v1[i+1]+v1[j]);
    max_sum=max(max_sum,_summ);
    
    j++;
    while(j<n){
        _summ+=(v1[j]-v1[i]);
        max_sum=max(max_sum,_summ);
        j++;
        i++;
    }
    j=0;
    _summ+=(v1[j]-v1[i]);
    max_sum=max(max_sum,_summ);
    i++;
    j++;
    _summ+=(v1[j]-v1[i]);
    max_sum=max(max_sum,_summ);
    return max_sum;
}

int main(){
    vector<int> v1={2, 5, 3, 1, 4, 9};
    cout<<max_triplet(v1)<<endl;
}
