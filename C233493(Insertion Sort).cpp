#include<iostream>
using namespace std;
int main()
{
    int n,i,key;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=2;j<=n;j++)
    {
        key=a[j];
        i=j-1;
        while (i > 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
            a[i+1]=key;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
