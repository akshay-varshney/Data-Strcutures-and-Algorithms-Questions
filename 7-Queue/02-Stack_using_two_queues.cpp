// Queue: Implement Stack using two Queues
//https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

#include <iostream>
#include <queue>

using namespace std;
class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
public:
    void push(int value);
    int pop();
    int top(){
        return q1.front();
    }
    int size(){
        return n;
    }
};

void Stack::push(int value){
    q2.push(value);
    n++;
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> temp=q1;
    q1=q2;
    q2=temp;
    cout<<"Value is pushed :"<<value<<endl;
}
int Stack::pop(){
    int val=q1.front();
    q1.pop();
    n--;
    return val;
}
// Time: O(n) for Push O(1) for Pop
// Space: O(n)

int main(){
    Stack S1;
    S1.push(11);
    S1.push(22);
    S1.push(33);
    cout<<S1.pop()<<endl;
    cout<<"Stack Size is: "<<S1.size()<<endl;
    cout<<"Stack TOP is: "<<S1.top()<<endl;
}
