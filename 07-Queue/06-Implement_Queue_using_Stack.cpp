// Queue: Implement Queue using Stack

#include <iostream>
#include <stack>

using namespace std;
class Queue{
    int n;
    stack<int> S1;
    stack<int> S2;
public:
    void Enque(int value);
    int Deque();
    int front(){
        return S1.top();
    }
    int size(){
        return n;
    }
};

void Queue::Enque(int value){
    cout<<"Value Pushed Inside the Queue: "<<value<<endl;
    S1.push(value);
    n++;
}

int Queue::Deque(){
    int value;
    while(!S1.empty()){
        value=S1.top();
        S2.push(value);
        S1.pop();
    }
    n--;
    stack<int> temp=S2;
    S2=S1;
    S1=temp;
    return value;
}

int main(){
    Queue Q1;
    Q1.Enque(1);
    Q1.Enque(2);
    Q1.Enque(3);
    Q1.Enque(4);
    cout<<"DeQUED: "<<Q1.Deque()<<endl;
    cout<<"Size of Queue is: "<<Q1.size()<<endl;
    cout<<"Fron Element of the Queue: "<<Q1.front()<<endl;
    cout<<"DeQUED: "<<Q1.Deque()<<endl;
    cout<<"Size of Queue is: "<<Q1.size()<<endl;
    cout<<"Fron Element of the Queue: "<<Q1.front()<<endl;
}
