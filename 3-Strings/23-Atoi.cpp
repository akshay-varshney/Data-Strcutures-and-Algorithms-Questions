// String: ATOI
/*
 Input : "9 2704"
 Output : 9
 */

#include<iostream>
#include<string>

using namespace std;
int atoi(string str){
    int result=0;
        int i=0;
        int sign = 1;
    // checking the sign of the string
        if(str[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(str[i]=='+'){
            sign=1;
            i++;
        }
        int count=0;
        while(str[i])
        {
            if(!(str[i]-'0'>=0 && str[i]-'0'<=9)){
                break;
            }
            result = result*10 + str[i]-'0'; // return the actual value by subtracting the ascii value of 0
            i++;
            count++;
        }
    // handling maximum and minimum case when it exceeds range of integers
        if(count>9 && sign==-1){
            result=INT_MIN;
        }
         if(count>9 && sign==1){
            result=INT_MAX;
        }
        return result*sign;
}
// time: O(n) and space: O(1)

int main(){
    string A="5121478262 8070067M75 X199R 547 8C0A11 93I630 4P4071 029W433619 M3 5 14703818 776366059B9O43393";
    cout<<atoi(A)<<endl;
}
