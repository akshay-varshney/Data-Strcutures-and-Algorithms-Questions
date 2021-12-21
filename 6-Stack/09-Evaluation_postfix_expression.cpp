// Stack: Evaluation of postfix expression
//https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1


#include <iostream>

using namespace std;

class Stack{
    int top;
public:
    int A[100];
    Stack(){
        top=-1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x){
    if(top>=100){
        cout<<"Stack is Full "<<endl;
        return false;
    }
    else{
        A[++top]=x;
        return true;
    }
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack is empty "<<endl;
        return 0;
    }
    else{
        int x=A[top--];
        return x;
    }
}
int Stack::peek(){
    if(top<0){
        return 0;
    }
    else{
        int x=A[top];
        return x;
    }
}
bool Stack::isEmpty(){
    return (top<0);
}

int postfix(const char *A){
    int n=strlen(A);
    Stack S1;
    for(int i=0;i<n;i++){
        if(isdigit(A[i])){
            S1.push(A[i]-'0');
        }
        else{
            int a=S1.pop();
            int b=S1.pop();
            switch (A[i]) {
                case '+':
                    S1.push(a+b);
                    break;
                case '-':
                    S1.push(b-a);
                    break;
                case '*':
                    S1.push(a*b);
                    break;
                case '/':
                    S1.push(b/a);
                    break;
                default:
                    break;
            }
        }
    }
    return S1.peek();
}


int main(){
    const char *A="231*+9-";
    cout<<postfix(A)<<endl;
}
