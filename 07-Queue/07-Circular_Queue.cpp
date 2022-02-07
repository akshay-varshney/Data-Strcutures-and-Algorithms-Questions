// Queue: Circular Queue

//https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/

#include <iostream>

using namespace std;

class Queue{
    int front;
    int rear;
    int *arr;
    int Size;
public:
    Queue(int s){
        Size=s;
        front=rear=-1;
        arr= new int[Size];
    }
    void Enqueue(int data);
    int Deque();
    void Print();
};

void Queue::Enqueue(int data){
    // checking the full condition if Queue is Full
    if( (front==0 && rear==Size-1) || (rear==(front-1)%(Size-1))){
        cout<<"Queue is FULL "<<endl;
        return;
    }
    // checking empty condition
    else if(front==-1){
        front=rear=0;
        arr[rear]=data;
    }
    // checking if rear has reached the end of the queue
    else if(rear==Size-1){
        rear=0;
        arr[rear]=data;
    }
    else{
        rear++;
        arr[rear]=data;
    }
    cout<<" The Value Enqueued is "<<data<<endl;
}

int Queue::Deque(){
    // empty condition
    if(front==-1){
        cout<<"Queue  is Empty "<<endl;
        return -1;
    }
    int ans=arr[front];
    arr[front]=-1;
    // one element
    if(front==rear){
        front=-1;
        rear=-1;
    }
    // if front has reached the end of the array.
    else if(front==Size-1){
        front=0;
    }
    else{
        front++;
    }
    return ans;
}

void Queue::Print(){
    if(front==-1){
        cout<<"Queue is Empty "<<endl;
        return;
    }
    cout<<"QUEUE is: ";
    if(rear>=front){
        
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i=front;i<Size;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rear;i++){
            cout<<arr[i]<<endl;
        }
    }
    cout<<endl;
}

int main(){
    Queue Q1(4);
    Q1.Deque();
    Q1.Enqueue(1);
    Q1.Enqueue(2);
    Q1.Enqueue(3);
    Q1.Enqueue(4);
    Q1.Enqueue(5);
    Q1.Print();
    Q1.Deque();
    Q1.Print();
}
