class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size();
            int left = 0, right = n - 1, index = n - 1;
    
            vector<int> ans(n);  
            
            while (left <= right) {
                int leftSquare = nums[left] * nums[left];
                int rightSquare = nums[right] * nums[right];
    
                if (leftSquare > rightSquare) {
                    ans[index--] = leftSquare;
                    left++;
                } else {
                    ans[index--] = rightSquare;
                    right--;
                }
            }
    
            return ans;  
        }
    };
    