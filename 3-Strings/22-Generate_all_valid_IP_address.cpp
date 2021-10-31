// String: Generate all valid IP Address from the string

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool Isvalid(string B){
    value=stoi(B);
    if(B.size()>1 && B[0]=='0'){
        return false;
    }
    if(value<=0 || value>255){
            return false;
        }
    return true;
}

vector<string> valid_IP(string A){
    int n=A.size();
    if(n<4 || n>12) return {};
    vector<string> ans;
    for(int i=1;i<4;i++){
        string first=A.substr(0,i);
        if(!Isvalid(first)){
            continue;
        }
        int j=1;
        while(i+j<n && j<4){
            string second=A.substr(i,j);
            if(!Isvalid(second)){
                j++;
                continue;
            }
            int k=1;
            while(i+j+k<n &&k<4){
                string third=A.substr(i+j,k);
                string fourth=A.substr(i+j+k);
                if(Isvalid(third) && (Isvalid(fourth))){
                    string current=first+"."+second+"."+third+"."+fourth;
                    ans.push_back(current);
                }
                k++;
            }
            j++;
        }
    }
    return ans;
}

int main(){
    string A="194236";
    vector<string> v2;
    v2=valid_IP(A);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<endl;
    }
}
