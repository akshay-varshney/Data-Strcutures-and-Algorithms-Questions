// Stack: Balanced Parantheses!



#include <iostream>

using namespace std;
#define MAX_LIMIT 100

class Stack{
    int top;
public:
    string A[MAX_LIMIT];
    Stack(){
        top=-1;
    }
    bool push(char x);
    string pop();
    string peek();
    bool isEmpty();
};

bool Stack::push(char x){
    if(top>=MAX_LIMIT){
        cout<<"Stack is Full "<<endl;
        return false;
    }
    else{
        A[++top]=x;
        return true;
    }
}

string Stack::pop(){
    if(top<0){
        cout<<"Stack is empty "<<endl;
        return "0";
    }
    else{
//        char x=;
        return A[top--];
    }
}

string Stack::peek(){
    if(top<0){
        return NULL;
    }
    else{
//        char x=;
        return A[top];
    }
}

bool Stack::isEmpty(){
    return (top<0);
}
Stack s1;

int valid_parenthesis(string A){
    int n=A.size();
    for(int i=0;i<n;i++){
        if(s1.isEmpty()){
            s1.push(A[i]);
        }
        else if(s1.peek()=="(" && A[i]==')'){
            s1.pop();
        }
        else{
            s1.push(A[i]);
        }
    }
    if(s1.isEmpty()){
        return 1;
    }
    return 0;
}
int main(){
    string A = "()";
    cout<<valid_parenthesis(A);
}
