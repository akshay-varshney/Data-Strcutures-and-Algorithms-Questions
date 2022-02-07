// Array: Uninon and Intersection two Array's
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/


#include<iostream>
#include<set>
#include<unordered_map>

using namespace std;

// Uninon of Array using set
int _union(int arr1[], int n1, int arr2[], int n2 ){
    set<int> s1;
    for(int i=0;i<n1;i++){
        s1.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        s1.insert(arr2[i]);
    }
    std::cout<<"Union: "<<std::endl;
    for(auto it=s1.begin();it!=s1.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl<<"Count of Union:  ";
    return s1.size();
    
}
// Intersection using unordered map
int _intersect(int arr1[], int n1, int arr2[], int n2 ){
    unordered_map<int,int> m1;
    pair<int,int> p1;
    for(int i=0;i<n1;i++){
        p1.first=arr1[i];
        p1.second=1;
        m1.insert(p1);
    }
    int count=0;
    std::cout<<"Intersection: "<<std::endl;
    for(int i=0;i<n2;i++){
        if(m1.count(arr2[i])){
            std::cout<<arr2[i]<<" ";
            count++;
        }
    }
    std::cout<<std::endl<<"Count of Intersection:  ";
    
    return count;
  
}

int main(){
    
    int arr1[]={5, 3};
    int arr2[]={1,2,3,4,5};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    std::cout<<_union(arr1, n1, arr2,n2)<<std::endl;
    std::cout<<_intersect(arr1, n1, arr2,n2)<<std::endl;
    return 0;
}


