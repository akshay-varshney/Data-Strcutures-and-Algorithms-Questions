
// Array: Factorial of large numbers
// https://www.interviewbit.com/problems/large-factorial/

#include<iostream>

using namespace std;

// This is not a very efficient way to do this. Efficient way is to use linked list.
int _multiply(int arr[], int ind, int val){
    int _carry=0;
    for(int i=0;i<ind;i++){
        int value=arr[i]*val+ _carry;
        arr[i]=value%10;
        _carry=value/10;

    }
    while(_carry){
        arr[ind]=_carry%10;
        _carry=_carry/10;
        ind++;
    }
    return ind;
}

std::string _factorial(int n){
    int arr[500];
    arr[0]=1;
    int ind=1;
    for(int i=2;i<=n;i++){
        ind=_multiply(arr,ind,i);
    }
    std::string ans;
    for(int i=ind-1;i>=0;i--){
        ans+=to_string(arr[i]);
    }
    return ans;
}

int main(){
    cout<<_factorial(105)<<endl;
}
