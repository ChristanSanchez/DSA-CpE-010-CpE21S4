#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    
    while (left<=right){
        int mid = left + (right-left)/2;
        
        if(arr[mid]==target){
            return mid;
        }
        if (arr[mid]<target){
            left = mid + 1;
        }
        else{
            right = mid-1;
        }
    }
    return-1;
}

int main()
{
    int arr[]={2,3,4,5,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    
    cout<<"Enter a number to search: ";
    cin>>target;
    
    int result = BinarySearch(arr,size,target);
    if (result !=-1){
        cout<<"Element found at index: "<<result<<endl;
        
    }
    else{
        cout<<"Element not found."<<endl;
    }
    
    return 0;
}