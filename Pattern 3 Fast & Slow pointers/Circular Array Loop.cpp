class Solution {
    public:
        bool circularArrayLoop(vector<int>& nums) 
        {
            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
             
                int slow=i;
                int fast=i;
                bool isPositive=nums[slow]>0;
    
                while(true)
                {
                    slow=nextIndex(slow,nums);
                    if(slow==-1||(nums[slow] > 0) != isPositive) break;
    
                    fast=nextIndex(fast,nums);
                    if(fast==-1||(nums[fast] > 0) != isPositive) break;
    
                    fast=nextIndex(fast,nums);
                    if(fast==-1||(nums[fast] > 0) != isPositive) break;
                    
                    if(slow==fast) return true;
                }
    
                
    
               
            }
    
            return false;
            
        }
    
    
        int nextIndex(int i,vector<int> & nums)
        {
            int n=nums.size();
            int digit=((i + nums[i]) % n + n) % n;
            
            return digit==i ? -1 : digit;
        }
    };