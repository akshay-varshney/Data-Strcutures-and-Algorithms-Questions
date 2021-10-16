// Array: Partition the array in three equal part so that sum of each part is same.

// https://www.interviewbit.com/problems/partitions/
/*
Input
A = 5
B = [1, 2, 3, 0, 3]

Output:

 2
*/

#include<vector>
#include<iostream>

using namespace std;
int partition(vector<int> A, int B){
    int _sum=0;
    for(int i=0;i<B;i++){
        _sum+=A[i];
    }
    if (_sum%3!=0) return 0;
    int max_sum=_sum/3;
    int count=0;
    vector<int> pre;
    vector<int> post;
    int summed=0;
    //Prefix array that will contain all the indexes which has values equal to required sum
    for(int i=0;i<B;i++){
        summed+=A[i];
        if(summed==max_sum) pre.push_back(i);
    }
    summed=0;
    //Suffix array that will contain all the indexes which has values equal to required sum
    for(int j=B-1;j>=0;j--){
        summed+=A[j];
        if(summed==max_sum) post.push_back(j);
    }
    // To check the sum is valid between the prefix and suffix. [((prefix=req_sum))--->|check between part if it has some equal to required sum |<--(suffix=req_sum)]
    for(int i=0;i<pre.size();i++){
        for(int j=0;j<post.size();j++){
            summed=0;
            bool flag=false; // This flag is to validate if the inputs are valid. In case prefix become greater then still it can increase count
            for(int k=pre[i]+1;k<post[j];k++){
                summed+=A[k];
                flag=true;
            }
            if(summed==max_sum && flag==true){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> v1={0,1,-1,0};
    vector<int> v2;
    cout<<partition(v1,v1.size())<<endl;
}
