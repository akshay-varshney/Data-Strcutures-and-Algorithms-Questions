// Array: N/3 Repeat Number
// https://www.interviewbit.com/problems/n3-repeat-number/
/*
 Input:[3 1 2 5 3]

 Output:[3, 4]
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Using extra space
int repeatedNumber(const vector<int> &A) {
    float n=A.size();
    float times=n/3;
    unordered_map<int,int> m1;
    for(int i=0;i<n;i++){
        unordered_map<int,int>::iterator iter=m1.find(A[i]);
        if(iter!=m1.end()){
            iter->second++;
        }
        else{
            m1.insert(std::make_pair(A[i],1));
        }
    }
    for(auto it=m1.begin();it!=m1.end();it++){
        if(it->second>=times){
            return it->first;
        }
    }
    return -1;
}

// without using extra space: The goal is take two variable and store count of two element, if third element comes out different then decrease the count
int repeat_count(vector<int> &A){
    int n=A.size();
    int first=INT_MAX;
    int second=INT_MAX;
    int count_1=0, count_2=0;
    int i=0;
    if (n<=2) return -1;
   while(i<n){
        if (first==A[i]) {
            count_1++;
        }
        else if(second==A[i]){
            count_2++;
        }
        else if(count_1==0){
            count_1++;
            first=A[i];
        }
        else if(count_2==0){
            count_2++;
            second=A[i];
        }
        else{
            count_1--;
            count_2--;
        }
       i++;
    }
    count_1=0,count_2=0;
    //traverese array again and see what is the actual count of those elements
    for(int i=0;i<n;i++){
        if(A[i]==first){
            count_1++;
        }
        else if(A[i]==second){
            count_2++;
        }
    }
    int count=0;
    int val;
    if(count_1>count_2){
        count=count_1;
        val=first;
    }
    else{
        val=second;
        count=count_2;
    }
    if(count> n/3){
        return val;
    }
    return -1;
}
//Time: O(n) and Space:O(n)

int main(){
    vector<int> v1={1, 1, 1, 2, 3, 5, 7};
    cout<<repeatedNumber(v1)<<endl;
    cout<<repeat_count(v1)<<endl;
}
