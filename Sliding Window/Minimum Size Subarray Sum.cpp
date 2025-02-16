class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            int i=0;
            int j=0;
            int n=nums.size();
            int sum=0;
            int size=n+1;
    
            while(j<n)
            {
                
                while(sum>=target)
                {
                    size=min(size,j-i);
                    sum=sum-nums[i++];
                }
                sum=sum+nums[j++];
    
            }
    
            while(sum>=target)
            {
                size=min(size,j-i);
                sum=sum-nums[i++];
            }
    
            return size==n+1 ? 0:size;
        }
    };