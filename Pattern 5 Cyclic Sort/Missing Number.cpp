class Solution {
    public:
        int missingNumber(vector<int>& nums) 
        {
            int i=0;
            int n=nums.size();
            while(i<n)
            {
                if(nums[i]==i || nums[i]==n)
                {
                    i++;
                }
                else
                {
                    swap(nums[i],nums[nums[i]]);
                }
            }
    
            for(int i=0;i<n;i++)
            {
                if(nums[i]!=i)
                {
                    return i;
                }
            }
    
            return n;
        }
    };