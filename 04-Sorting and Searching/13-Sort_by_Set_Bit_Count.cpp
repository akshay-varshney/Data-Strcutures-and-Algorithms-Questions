// Searching & Sorting: Sort by Set Bit Coun
//https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#

#include<iostream>
#include<vector>

using namespace std;
int convert_binary(int A){
    string ans="";
    int count=0;
    while(A>0){
        ans+=to_string(A%2);
        if(A%2==1){
            count++;
        }
        A=A/2;
    }
    cout<<ans<<endl;
    return count;
}

bool compare(int a, int b){
    int countA=convert_binary(a);
    int countB=convert_binary(b);
    if(countA>countB){
        return true;
    }
    return false;
}

void sort_bits(vector<int> &A){
    int n=A.size();
    sort(A.begin(),A.end(),compare);
}
int main(){
    vector<int> v1= {1, 2, 3, 4, 5, 6};
    sort_bits(v1);
    for(auto it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
}
