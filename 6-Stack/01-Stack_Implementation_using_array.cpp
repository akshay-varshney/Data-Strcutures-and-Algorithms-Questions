// Linked List: Add two numbers as list
//https://www.interviewbit.com/problems/add-two-numbers-as-lists/


#include <iostream>

using namespace std;
#define MAX_LIMIT 100

class Stack{
    int top;
public:
    int A[MAX_LIMIT];
    Stack(){
        top=-1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x){
    if(top>=MAX_LIMIT){
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

int main(){
    class Stack s1;
    s1.push(3);
    s1.push(4);
    s1.push(12);
    s1.push(41);
    s1.push(112);
    s1.push(24);
    s1.push(142);
    cout<<s1.pop()<<endl;
    while(!s1.isEmpty()){
        cout<<s1.peek()<<" ";
        s1.pop();
    }
    cout<<endl;
}
