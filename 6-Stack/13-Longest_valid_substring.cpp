// Stack: Longest Valid Substring.
//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

#include <iostream>
#include <stack>
using namespace std;


// Method 1: By using Stack :
// Time :O(n) and Space O(n)
int findMaxLen(string str)
{
    int n = str.length();
    stack<int> S;
    S.push(-1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '('){
            S.push(i);
        }
        else{
            if (!S.empty()) S.pop();
            if (!S.empty())  result = max(result, i - S.top());
            else S.push(i);
        }
    }
    return result;
}

// Method 2: By taking two pointers left and right and traversing first from left to right and then from right to left.
int MaximumLengthSubs(string s)
{
    int n=s.size();
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '(')
            left++;
        else
            right++;
        
        if (left == right)
            maxlength = max(maxlength, 2 * right);
        else if (right > left)
            left = right = 0;
    }

    left = right = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxlength = max(maxlength, 2 * left);
        else if (left > right)
            left = right = 0;
    }
    return maxlength;
}

int main()
{
    string str = "()))()()";
    cout << findMaxLen(str) << endl;
    cout << MaximumLengthSubs("()))()()()");
    return 0;
}


