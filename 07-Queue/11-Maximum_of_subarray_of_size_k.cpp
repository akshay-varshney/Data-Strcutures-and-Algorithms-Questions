// Maximum of all Sub-array of size-k
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include <iostream>
#include<deque>
#include <vector>

using namespace std;

// Method 1: By using sliding window and iterating over each element
void Printmaxsubarray(vector<int> A, int k){
    int n=A.size();
    int i=0;
    while (i+k <= n) {
        int maxi= A[i];
        int j=i+1;
        while(j< i+k){
            if(A[j] >maxi){
                maxi=A[j];
            }
            j++;
        }
        cout<<maxi<<" ";
        i++;
    }
}
// Time: O((n-k)*k)


// Method 2: By using doubley ended Queue
void printKMax(int arr[], int n, int k)
{
    std::deque<int> Q(k);
    int i=0;
    // Iterating first k elements and if the next element is greater then pop the last element and store the index of next element
    while(i<k)
    {
        while ((!Q.empty()) && arr[i] >=arr[Q.back()])
            Q.pop_back();
        
        Q.push_back(i);
        i++;
    }

    while(i<n)
    {
        cout << arr[Q.front()] << " ";
        // Check if the current element in the Queue has reached value greater than it's own window.
        while ((!Q.empty()) && Q.front() <=i - k)
            Q.pop_front();
        
        //if the next element is greater then pop the last element and store the index of next element
        while ((!Q.empty()) && arr[i] >=arr[Q.back()])
            Q.pop_back();
        
        Q.push_back(i);
        i++;
    }
    cout << arr[Q.front()];
}

int main()
{
    
    int arr[] = { 12, 1, 78,90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}

