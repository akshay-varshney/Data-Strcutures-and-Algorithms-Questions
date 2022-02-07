// Stack: Find the next greater Elment
/*
 Input:
 N = 4, arr[] = [1 3 2 4]
 Output:
 3 4 4 -1
 
 */

#include <iostream>
#include <vector>
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
vector<long long > next_greater(vector<long long> &A){
    int n=A.size();
    Stack S;
    vector<long long> greater(n,-1);
    int i=0;
    while(i<n){
        if(S.isEmpty()){
            S.push(i);
            i++;
        }
        else if(A[S.peek()]>A[i]){
            S.push(i);
            i++;
        }
        else{
            greater[S.pop()]=A[i];
        }
    }
    return greater;
}

int main(){
    vector<long long> v1={11, 13, 21, 3};
    vector<long long> v2=next_greater(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
