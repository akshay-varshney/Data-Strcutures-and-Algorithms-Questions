// Stack: Implemet Two Stacks in an Array.

//https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
#include <iostream>

using namespace std;

class Stack {
    int* arr;
    int size;
    int top1, top2;

public:
    Stack(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
        else {
            return ;
        }
    }
    
    void push2(int x)
    {
        // There is at least one empty
        // space for new element
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
        else {
            return;
        }
    }

    int pop1()
    {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }
        else return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else return -1;
    }
    void Print_data()
    {
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Stack s1(5);
    s1.push1(5);
    s1.push2(10);
    s1.push2(15);
    s1.push1(11);
    s1.push2(7);
    s1.Print_data();
    cout<< s1.pop1()<<endl;
    s1.Print_data();
    s1.push2(40);
    s1.Print_data();
    cout << s1.pop2()<<endl;
    s1.Print_data();
    return 0;
}
