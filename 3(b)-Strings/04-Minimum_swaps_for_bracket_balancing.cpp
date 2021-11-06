// String: Minimum Swaps for Bracket Balancing
//https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/

/*
 Input  : []][][
 Output : 2
 */
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int minimum_swaps(string A){
    int open=0;
    int close=0;
    int n=A.size();
    int defect=0;
    int ans=0;
    //Taken defect count when we get unbalancing the defect count will increase we'll add the defect count in answer and that will be counted as adjacent swap.
    for(int i=0;i<n;i++){
        if(A[i]==']'){
            close++;
            defect=close-open;
        }
        else{
            open++;
            if(defect>0){
                ans+=defect;
                defect--; // decreasing count by 1 as one defect is fixed with the swap.
            }
        }
    }
    return ans;
}
//Time: O(n) and space:O(1)


int main(){
    string A="[[][]]";
    cout<<minimum_swaps(A)<<endl;
  
}
