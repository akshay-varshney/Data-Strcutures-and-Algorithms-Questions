// Searching: Square Root of a number using binary Search

#include<iostream>
#include<vector>

using namespace std;


int squareroot(int A)
{
    if (A == 0 || A == 1)
        return A;
    int start = 1, end = A/2, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        int sqr = mid * mid;
        if (sqr == A){
            return mid;
        }
        else if(sqr <= A) {
            start = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
//Time: O(logn) space: O(1)

int main(){
    int A=15;
    cout<<squareroot(A)<<endl;
}
