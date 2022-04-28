// Array: Minimum Number of Jumps
//https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

#include<iostream>
#include<vector>

using namespace std;

int minJumps(int arr[], int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    
    int maxReach = arr[0];

    int step = arr[0];
    int jump = 1;
    int i = 1;
    for (i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
}


int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout <<minJumps(arr, size)<<endl;
    return 0;
}





