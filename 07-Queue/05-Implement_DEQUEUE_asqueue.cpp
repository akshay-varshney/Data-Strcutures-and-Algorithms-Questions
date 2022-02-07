// Queue: Implement Deque as Queue


#include <iostream>
//#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
};
class DeQueue: public Node{
private:
    Node* front=NULL;
    Node* rear=NULL;
public:
    void Enque(int x);
    void Deque();
    bool isEmpty(){
        return (front==NULL);
    }
    int Size();
    void Print();
};

int DeQueue::Size(){
    if(!isEmpty())
    {
        Node *temp=front;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    return 0;
}


void DeQueue::Enque(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        temp->next=temp->prev=NULL;
        return;
    }
    rear->next=temp;
    temp->next= NULL;
    temp->prev=rear;
    rear=temp;
}

void DeQueue::Deque(){
    if(!isEmpty()){
        Node *temp= front;
        cout<<"Element dequed is: "<<temp->data<<endl;
        front=front->next;
        if(front){
            front->prev=NULL;
        }
        if(rear==NULL){
            rear=NULL;
        }
        delete temp;
    }
}

void DeQueue::Print() {
    Node* temp = front;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class Queue: public DeQueue{
public:
    void enque(int data){
        Enque(data);
    }
    void deque(){
        Deque();
    }
    void display(){
        Print();
    }
};

int main(){
    Queue Q1;
    Q1.enque(1);
    Q1.enque(2);
    Q1.enque(3);
    Q1.enque(4);
    cout << "Queue: ";
    Q1.display();
    Q1.deque();
    cout << "Queue: ";
    Q1.display();
    Q1.enque(5);
    cout<<"Queue is: ";
    Q1.display();
    cout<<"Queue size: "<<Q1.Size()<<endl;
    cout<<"Queue is empty: "<<Q1.isEmpty()<<endl;
    Q1.deque();
    cout << "Queue: ";
    Q1.display();
}
