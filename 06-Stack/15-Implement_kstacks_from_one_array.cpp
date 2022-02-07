// Queue: Implement k-Stacks from a single Array

//https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

#include <iostream>

using namespace std;

class kStacks{
    int *arr;
    int *top;
    int *next;
    
    int n, k, freeElement;
public:
    kStacks(int x, int N);
    bool isFull(){
        return (freeElement==-1);
    }
    void push(int value, int stackNum);
    int pop(int stackNum);
    bool isEmpty(int stackNum){
        return (top[stackNum]==-1);
    }
};

kStacks::kStacks(int x, int N){
    k=x;
    n=N;
    arr= new int[n];
    top= new int[k];
    next=new int[n];
    freeElement=0;
    for(int i=0;i<k;i++){
        top[i]=-1;
    }
    for(int i=0;i<n-1;i++){
        next[i]=i+1;
    }
    next[n-1]=-1;
}

void kStacks::push(int value, int stackNum){
    if(isFull()){
        cout<<"Stack is FULL "<<endl;
        return;
    }
    int i=freeElement;
    freeElement=next[i];
    next[i]=top[stackNum];
    top[stackNum]=i;
    arr[i]=value;
    cout<<"Value pushed in stack number: "<<stackNum<<" and value is "<<value<<endl;
}

int kStacks::pop(int stackNum){
    if(isEmpty(stackNum)){
        cout<<"Stack is Empty "<<endl;
        return -1;
    }
    
    int i=top[stackNum];
    top[stackNum]=next[i];
    next[i]=freeElement;
    freeElement=i;
    return arr[i];
}

int main(){
    int k = 3, n = 10;
    kStacks ks(k, n);
    ks.push(15, 2);
    ks.push(45, 2);
    
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
    
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
}

