// Queue: Implementation if Queue using Arrays
//https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
#include <iostream>

using namespace std;
class Queue{
public:
    int front, rear, size;
    int capacity;
    int *arr;
};

Queue* Create_Queue(int capacity){
    Queue* queue= new Queue();
    queue->capacity= capacity;
    queue->front=queue->size=0;
    queue->rear=capacity-1;
    queue->arr= new int[queue->capacity];
    return queue;
}

int isFull(Queue* queue){
    return  (queue->size==queue->capacity);
}

int isEmpty(Queue* queue){
    return (queue->size==0);
}

void enqueue(Queue* queue, int value){
    if(isFull(queue))
        return;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=value;
    cout<<"ENQUE: "<< value<<endl;
    queue->size++;
}

int dequeue(Queue* queue){
    if(isEmpty(queue))
        return NULL;
    int value=queue->arr[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size=queue->size-1;
    return value;
}

int front(Queue* queue){
    if(isEmpty(queue)){
        return NULL;
    }
    return queue->arr[queue->front];
}

int rear (Queue* queue){
    if(isEmpty(queue))
        return NULL;
    return queue->arr[queue->rear];
}


int main(){
    Queue* queue= Create_Queue(100);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    cout<<"DEQUED: "<<dequeue(queue)<<endl;
    cout<<"FRONT: "<<front(queue)<<endl;
    cout<<"REAR "<<rear(queue)<<endl;
}
