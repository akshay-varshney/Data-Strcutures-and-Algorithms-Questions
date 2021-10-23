// Sthighing:  print all permutations of a given string
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>
#include<string>
using namespace std;

void permutation (string a, int low, int high){
    if (low == high){
        cout<<a<<endl;
    }
    else{
        for (int i = low; i <= high; i++){
            swap(a[low], a[i]);
            permutation(a, low+1, high);
            swap(a[low], a[i]);
            }
        }
}
// time: O(n*!n) space: O(1)
int main(){
    string v1="abc";
    permutation(v1, 0, v1.size()-1);
}
