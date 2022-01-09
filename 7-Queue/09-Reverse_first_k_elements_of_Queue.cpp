// Queue: Reverse first K element of a queue
/*
 Reversing a Queue
 Input:
 5 3
 1 2 3 4 5

 Output:
 3 2 1 4 5
 
 */


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> reverse(queue<int> Q, int count){
    stack<int> ans;
    queue<int> Final;
    int val=0;
    while(!Q.empty() && val<count){
        val++;
        int data=Q.front();
        Q.pop();
        ans.push(data);
    }
    while(!ans.empty()){
        int data=ans.top();
        ans.pop();
        Final.push(data);
    }
    while(!Q.empty()){
        int data=Q.front();
        Q.pop();
        Final.push(data);
    }
    return Final;
}


int main(){
    queue<int> Q1;
    Q1.push(1);
    Q1.push(2);
    Q1.push(3);
    Q1.push(4);
    Q1.push(5);
    queue<int> V1=reverse(Q1,3);
    cout<<"Reversed Queue "<<" ";
    while (!V1.empty()) {
        cout<<V1.front()<<" ";
        V1.pop();
    }
    cout<<endl;
}
