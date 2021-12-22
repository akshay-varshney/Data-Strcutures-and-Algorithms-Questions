// Stack: Sort a Stack
//https://practice.geeksforgeeks.org/problems/sort-a-stack/1

#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

string ns;

void insert_at_bottom(int x)
{
    if(st.size() == 0)
    st.push(x);

    else
    {
        int a = st.top();
        st.pop();
        int p,z;
        if(a>x){
            p=a;
            z=x;
        }
        else{
            p=x;
            z=a;
        }
        insert_at_bottom(z);
        st.push(p);
    }
}

void reverse()
{
    if(st.size()>0)
    {
        int x = st.top();
        st.pop();
        reverse();
        insert_at_bottom(x);
    }
}

int main()
{
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);
    reverse();
    cout<<"Sorted Stack"<<endl;
    while(!st.empty())
    {
        int p=st.top();
        st.pop();
        cout<<p<<" ";
    }
    cout<<endl;
}
