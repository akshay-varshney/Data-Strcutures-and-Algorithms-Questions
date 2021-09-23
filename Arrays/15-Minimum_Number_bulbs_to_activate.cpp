// Array: Minimum Lights to Activate the entire array
// https://www.interviewbit.com/problems/minimum-lights-to-activate/

/*
 position X, it can light the corridor from [ X-B+1, X+B-1]
 Input=
 A = [ 0, 0, 1, 1, 1, 0, 0, 1].
 B = 3
 
 O/p: 2
 
 */

#include<vector>
#include<iostream>

using namespace std;


int steps(vector<int> &A, int B){
    int bulb=0;
    bool flag=false;
    int n=A.size();
    int val;
    int i=0;
    while(i<n){
        int j=i+B-1; // Checking bulbs from right side of the range and if it is found working activate it and increase i by 2*n-1 times.
        flag=false;
        while(j>=i-B+1){
            if(A[j]==1){
                flag=true;
                val=j;
                bulb++;
                i=val+B;
                break;
            }
            j--;
        }
        if(flag==false){
            return -1;
        }
    }
    return bulb;
}

int main(){
    vector<int> v1={0, 0, 1, 1, 1, 0, 0, 1};
    int B=3;
    cout<<steps(v1,B)<<endl;
}
