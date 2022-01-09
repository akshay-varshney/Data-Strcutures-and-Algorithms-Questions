// Queue: Interleave the first half of the queue with second half

// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

/*
 Input :  1 2 3 4
 Output : 1 3 2 4

 Input : 11 12 13 14 15 16 17 18 19 20
 Output : 11 16 12 17 13 18 14 19 15 20
 
 */


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> interleave(queue<int> Q){
    queue<int> Q1;
    queue<int> Q2;
    int count=0;
    int n=Q.size();
    while(count<n/2){
        int data=Q.front();
        Q.pop();
        count++;
        Q1.push(data);
    }
    while(count<n){
        int data=Q.front();
        Q.pop();
        count++;
        Q2.push(data);
    }
    while(!Q1.empty() && ! Q2.empty()){
        int d1=Q1.front();
        int d2=Q2.front();
        Q.push(d1);
        Q.push(d2);
        Q1.pop();
        Q2.pop();
    }
    return Q;
}


int main(){
    queue<int> Q1;
    Q1.push(11);
    Q1.push(12);
    Q1.push(13);
    Q1.push(14);
    Q1.push(15);
    Q1.push(16);
    Q1.push(17);
    Q1.push(18);
    Q1.push(19);
    Q1.push(20);
//    Q1.push(5);
    queue<int> V1=interleave(Q1);
    cout<<"Interleaved Queue is "<<" ";
    while (!V1.empty()) {
        cout<<V1.front()<<" ";
        V1.pop();
    }
    cout<<endl;
}
