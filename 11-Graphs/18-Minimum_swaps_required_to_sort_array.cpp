// Graph:minimum number of swaps required to sort an array
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/


#include<iostream>
#include<vector>
#include<map>

using namespace std;


int minSwaps1(vector<int> arr, int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    // sort the pair according to the their values
    std::sort(arrPos, arrPos + n);
    // visited array to keep track of which elements are visited in array
    vector<bool> visited(n, false);

    // Initialize result
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] || arrPos[i].second == i)
            continue;

        int value = 0;
        int j = i;
        // If elemenet is not visited then keep moving towards those unvisited indexes whose and find the cycle
        while (!visited[j])
        {
            visited[j] = 1;

            j = arrPos[j].second;
            value++;
        }
        
        if (value > 0)
        {
            ans += (value - 1);
        }
    }
    return ans;
}
// Time: O(nlogn)
// space: O(n)

int main()
{
    vector <int> a = {2,8,5,4};
    int n = a.size();
    cout << minSwaps1(a, n);
}

