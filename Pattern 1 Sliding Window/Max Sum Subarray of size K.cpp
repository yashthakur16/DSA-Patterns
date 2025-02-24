//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) 
    {
        int maxi=INT_MIN;
        int sum=0;
        
        for(int i=0;i<k;i++)
        {
            sum=sum+arr[i];
        }
        
        maxi=max(sum,maxi);
        
        int j=k;
        int i=0;
        int n=arr.size();
        
        while(j<n)
        {
            sum=sum-arr[i++];
            sum=sum+arr[j++];
            
            maxi=max(sum,maxi);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends