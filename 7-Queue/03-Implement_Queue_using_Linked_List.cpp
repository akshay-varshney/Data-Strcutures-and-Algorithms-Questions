// Queue: Implement Queue using Linked List


#include <iostream>
//#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
class Queue: public Node{
public:
    Node* front=NULL;
    Node* rear=NULL;
    void Enqueue(int x);
    void Dequeue();
    int Front(){
        return front->data;
    }
    void Print();
};

void Queue::Enqueue(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp; // storing the address of the next pointer to be attached
    rear=rear->next; // moving rear to the newly created Node
    delete temp;
}

void Queue::Dequeue(){
    Node *temp=front;
    if(front==NULL){
        return ;
    }
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    delete temp;
}
void Queue::Print() {
    Node* temp = front;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
using namespace std;

int main(){
    Queue Q1;
    Q1.Enqueue(2);
    Q1.Print();
    Q1.Enqueue(3);
    Q1.Print();
    Q1.Enqueue(4);
    Q1.Print();
    Q1.Enqueue(5);
    Q1.Print();
    Q1.Enqueue(6);
    Q1.Print();
    Q1.Dequeue();
    Q1.Print();
}
