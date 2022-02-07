// Array: Prime Numbers

#include<iostream>
#include<vector>

using namespace std;

vector<int> primes(int A) {
    vector<int> ans={};
    if(A<2) return ans;
    for(int i=2;i<=A;i++){
        int upper=sqrt(i);
        bool flag=false;
        for(int j=2;j<=upper;j++)
        {
            if(i%j==0)
            {
                flag=true;
                break;
            }
            else flag=false;
        }
        if(flag==false) ans.push_back(i);
    }
    return ans;
}
//Time: O(nlogn(n)) and Space:O(n)

int main(){
    vector<int> v2;
    v2=primes(20);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
