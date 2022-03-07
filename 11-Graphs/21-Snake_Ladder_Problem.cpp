//Graph: Snake Ladder Problems
//https://www.geeksforgeeks.org/snake-ladder-problem-2/


#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Queue{
    int V;
    int distance;
};

int getMinthrow(vector<int> & board){
    int n=board.size();
    vector<bool> visited(n,false);
    queue<Queue> Q;
    visited[0]= true;
    Q.push({0,0});
    while(!Q.empty()){
        auto it=Q.front();
        int vertex= it.V;
        if(vertex==n-1)
            break;
        Q.pop();
        for(int i=vertex+1;i<=(vertex+6);i++){
            if(visited[i]==false){
                Queue temp;
                temp.distance = it.distance +1;
                visited[i]= true;
                if(board[i]!=-1)
                    temp.V=board[i];
                else
                    temp.V= i;
                Q.push(temp);
                
            }
        }
    }
    return Q.front().distance ;
}


int main(){
    int n=30;
    vector<int> board(n,-1);
    board[2]=21;
    board[4]=7;
    board[10]=25;
    board[19]=28;
    board[26]=0;
    board[20]=8;
    board[16]=3;
    board[18]=6;
    cout<<getMinthrow(board)<<endl;
}
