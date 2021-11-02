// String: Convert Integer to Roman
//https://www.interviewbit.com/problems/integer-to-roman/

#include<iostream>
#include<string>


using namespace std;

string integer_ToRoman(int num){
    string m[] = { "", "M", "MM", "MMM" };
        string c[] = { "",  "C",  "CC",  "CCC",  "CD",
                       "D", "DC", "DCC", "DCCC", "CM" };
        string x[] = { "",  "X",  "XX",  "XXX",  "XL",
                       "L", "LX", "LXX", "LXXX", "XC" };
        string i[] = { "",  "I",  "II",  "III",  "IV",
                       "V", "VI", "VII", "VIII", "IX" };
     
        
        string thousands = m[num / 1000];
        string hundereds = c[(num % 1000) / 100];
        string tens = x[(num % 100) / 10];
        string ones = i[num % 10];
     
        string ans = thousands + hundereds + tens + ones;
     
        return ans;
}

int main(){
    int A=3114;
    cout<<integer_ToRoman(A)<<endl;
}
