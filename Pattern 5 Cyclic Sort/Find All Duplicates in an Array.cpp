class Solution {
    public:
        vector<int> findDuplicates(vector<int>& arr) 
        {
            int n=arr.size();
            int i=0;
    
            while(i<n)
            {
                if(arr[i]==i+1 || arr[i]==arr[arr[i]-1])
                {
                    i++;
                }
                else
                {
                    swap(arr[i],arr[arr[i]-1]);
                }
            }
    
            vector<int> ans;
    
            for(int i=0;i<n;i++)
            {
                if(arr[i]!=i+1)
                {
                    ans.push_back(arr[i]);
                }
            }
    
            return ans;
            
        }
    };