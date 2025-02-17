class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            unordered_map<int,int> mpp;
            mpp[nums[0]]=0;
            int n=nums.size();
    
            for(int i=1;i<n;i++)
            {
                if(mpp.find(target-nums[i])!=mpp.end())
                {
                    return {mpp[target-nums[i]],i};
                }
                else
                {
                    mpp[nums[i]]=i;
                }
            }
    
            return {};
        }
    };