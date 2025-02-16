class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) 
        {
            int i=0;
            int j=0;
            int n=nums.size();
            int size=0;
    
    
            while(j<n)
            {
               if(nums[j]==0) k--;
    
               while(k<0)
               {
                if(nums[i]==0) k++;
                i++;
               }
    
               size=max(size,j-i+1);
               j++;
    
            }
    
            return size;
            
        }
    };