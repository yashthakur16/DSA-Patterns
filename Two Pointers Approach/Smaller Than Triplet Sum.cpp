#include <bits/stdc++.h> 
int threeSumSmaller(int n, vector<int> arr, int target) 
{
    sort(arr.begin(),arr.end());

    int ans=0;

    for(int i=0;i<n-2;i++)
    {

        int j=i+1;
        int k=n-1;

        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];

            if(sum<target)
            {
               ans=ans+k-j;
               j++;
            }
            else
            {
                k--;
            }

        }
    }

    return ans;
}
