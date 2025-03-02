class Solution {
    public:
        bool circularArrayLoop(vector<int>& nums) 
        {
            int n=nums.size();
    
            for(int i=0;i<n;i++)
            {
    
                if(nums[i]==0) continue;                
                int slow=i;
                int fast=i;
    
                bool isPositive=nums[slow]>0;
    
    
                while(true)
                {
                    slow=solve(slow,isPositive,nums);
    
                    if(slow==-1) break;
    
                    fast=solve(fast,isPositive,nums);
    
                    if(fast==-1) break;
    
                    fast=solve(fast,isPositive,nums);
    
                    if(fast==-1) break;
    
                    if(slow==fast)  return true;
                }
    
                int index=i;
    
         
                while (solve(index, nums[i] > 0, nums) != -1) {
                    int temp = index;
                    index = solve(index, nums[i] > 0, nums);
                    nums[temp] = 0;  
                }
            }
    
            return false;
            
        }
    
    
        int solve(int i,bool isPositive,vector<int> &nums)
        {
            int n=nums.size();
            int index=((i + nums[i]) % n + n) % n;
    
            if((nums[index]>0)!=isPositive) return -1;
    
            if(index==i) return -1;
    
            return index;
        }
    };