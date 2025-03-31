#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5]={3,1,5,4,2};
    int n=5;
    int i=0;

    while(i<n)
    {
        if(arr[i]==i+1)
        {
            i++;
        }
        else
        {
            swap(arr[i],arr[arr[i]-1]);
        }
    }

    for(auto i : arr)
    {
        cout<<i<<" ";
    }

    return 0;
}