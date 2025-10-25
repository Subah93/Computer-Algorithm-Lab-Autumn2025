#include <iostream>
using namespace std;
int main() {
    int n,key,mid,low,high;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements in sorted order: ";
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }
    cout<<"Enter element to search: ";
    cin>>key;

    low =0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high)/2;

        if (arr[mid]==key) {
            cout <<"Element found at position "<< mid + 1<<endl;
            return 0;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << "Element not found in the array."<<endl;
    return 0;
}

