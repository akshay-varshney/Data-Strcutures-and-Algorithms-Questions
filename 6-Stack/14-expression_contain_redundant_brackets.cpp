// Stack: Expression contains redundant bracket or not
// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

#include <iostream>
#include <stack>
using namespace std;


bool FindRedundant(string A){
    int n=A.size();
    stack<char> S;
    for(int i=0;i<n;i++){
        if(A[i]==')'){
            int top=S.top();
            S.pop();
            bool flag=true;
            while(!S.empty() && top!='('){
                if(top=='+' || top=='*' || top=='-' || top=='/'){
                    flag=false;
                }
                top=S.top();
                S.pop();
            }
            if(flag){
                return true;
            }
        }
        else{
            S.push(A[i]);
        }
    }
    return false;
}

int main()
{
    string str = "((a+b))";
    cout<<FindRedundant(str)<<endl;
    str = "(a+(b)/c)";
    cout<<FindRedundant(str)<<endl;
    return 0;
}
