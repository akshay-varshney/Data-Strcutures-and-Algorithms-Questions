// Searching:Middle of three elemm=net


#include<iostream>
using namespace std;

int middle_element(int A, int B, int C){
    if((A>C && A<B) || (A>B && A<C)){
        return A;
    }
    else if((C>A && C<B) || (C>B && C<A)){
        return C;
    }
    else{
        return B;
    }
    return -1;
}

int main(){
    int A=10, B=20,C=15;
    cout<<middle_element(A, B, C)<<endl;
}
