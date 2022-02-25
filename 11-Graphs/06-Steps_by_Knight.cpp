//Graph: find minimum steps to reach to specific Path in minimum moves by Knight
//https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

#include <iostream>
#include<queue>

using namespace std;

class Path
{
public:
    int x, y;
    int dis;
    Path() {};
    Path(int x, int y, int dis) : x(x), y(y), dis(dis) {};
};
  

bool isValid(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
  

int minStepToReachTarget(int knightPos[], int target[], int N)
{
    // x and y direction for all possible moves of a knight.
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    queue<Path> q;
    q.push(Path(knightPos[0], knightPos[1], 0));
    Path t;
    int x, y;
    bool visit[N + 1][N + 1];
    // make all Path unvisited
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
  
    // visit starting state
    visit[knightPos[0]][knightPos[1]] = true;
  
    // loop untill we have one element in queue
    while (!q.empty())
    {
        t = q.front();
        q.pop();
  
        // if current Path is equal to target Path,
        // return its distance
        if (t.x == target[0] && t.y == target[1])
            return t.dis;
  
        // loop for all reachable states
        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
  
            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isValid(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(Path(x, y, t.dis + 1));
            }
        }
    }
    return -1;
}

int main()
{
    int N = 6;
    int knightPos[] = {4, 5};
    int target[] = {1, 1};
    cout << minStepToReachTarget(knightPos, target, N)<<endl;
    return 0;
}
