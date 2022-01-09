// Queue: Reverse a Queue
// https://www.geeksforgeeks.org/reversing-a-queue/


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> reverse(queue<int> Q){
    stack<int> ans;
    while(!Q.empty()){
        int data=Q.front();
        Q.pop();
        ans.push(data);
    }
    while(!ans.empty()){
        int data=ans.top();
        ans.pop();
        Q.push(data);
    }
    return Q;
}


int main(){
    queue<int> Q1;
    Q1.push(1);
    Q1.push(2);
    Q1.push(3);
    queue<int> V1=reverse(Q1);
    cout<<"Reversed Queue "<<" ";
    while (!V1.empty()) {
        cout<<V1.front()<<" ";
        V1.pop();
    }
    cout<<endl;
}
