//program to reverse an array
//Q. https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/#
#include<iostream>

using namespace std;

// Recurisve way to swap array
void recursive_reversed(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    swap(arr[start],arr[end]);
    recursive_reversed(arr, start+1, end-1);
}

// Generalizing the function for both the string and array
template <class t>
t reversed(t value, int start, int end){
    while(start<=end){
        swap(value[start], value[end]);
        start++;
        end--;
    }
    return value;
}
int main() {
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int arr[n];
    int temp;
    for(int i=0;i<n;i++){
        cout<<"Enter the element: ";
        cin>>temp;
        arr[i]=temp;
    }
    int start=0;
    int end=n-1;

    reversed(arr, start, end);
    std::string name="Akshay";
    std::cout<<reversed(name, 0, 5)<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//Time Complexity : O(n)

