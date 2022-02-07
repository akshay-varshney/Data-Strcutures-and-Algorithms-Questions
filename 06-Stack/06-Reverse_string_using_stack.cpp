// Stack: Reverse a string using Stack

#include <iostream>

using namespace std;

class Stack{
    
    int top;
    public:
    string arr[100];
        Stack(){
            top=-1;
        }
    void push(char value){
        arr[++top]=value;
    }
    string pop(){
        return arr[top--];
    }
};

int main(){
    string A="Akshay";
    Stack S1;
    for(int i=0;i<A.size();i++){
        S1.push(A[i]);
    }
    string ans="";
    for(int i=0;i<A.size();i++){
        ans+=S1.pop();
    }
    cout<<ans<<endl;
}
