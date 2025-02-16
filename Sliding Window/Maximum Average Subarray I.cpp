class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) 
        {
            double maxi=INT_MIN;
            double sum=0;
    
            for(int i=0;i<k;i++)
            {
                sum=sum+nums[i];
            }
    
            maxi=max(sum,maxi);
    
            int j=k;
            int i=0;
            int n=nums.size();
    
            while(j<n)
            {
                sum=sum-nums[i++];
                sum=sum+nums[j++];
    
                maxi=max(sum,maxi);
            }
    
            return maxi/k;
    
            
        }
    };