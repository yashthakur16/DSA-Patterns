class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) 
        {
            int n=nums.size();
            int i=0;
            int j=0;
    
            int product=1;
            int ans=0;
    
            if(k<=1) return 0;
    
            while(j<n)
            {
                product*=nums[j];
    
                while(product>=k) product/=nums[i++];
    
                ans+=j-i+1;
                j++;
            }
            
            return ans;
        }
    };