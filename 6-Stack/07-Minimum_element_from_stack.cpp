// Stack:Get the Minimum element from the stack in the O(1)

//https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

#include <iostream>
#include <stack>
using namespace std;

struct MyStack
{
    stack<int> s;
    int minEle;

    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout <<"Minimum element: "<<minEle << "\n";
    }

    void peek()
    {
        if (s.empty())
        {
            return;
        }

        int t = s.top();
        minEle=min(minEle,t);
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }

        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }
        else
            cout << t << "\n";
    }

    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }
        else if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }

        else
        s.push(x);

        cout << "Number Inserted: " << x << "\n";
    }
};

int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
}
