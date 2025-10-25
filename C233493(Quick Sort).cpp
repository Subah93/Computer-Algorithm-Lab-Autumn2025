#include <iostream>
using namespace std;
int partition(int arr[], int l, int h) {
    int p = arr[h];
    int i = l - 1;
    for (int j = p; j < h-1; j++) {
        if (arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}
void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int main() {
    int n;
    cout<<"Elements : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
