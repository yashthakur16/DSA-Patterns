class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
        {
            vector<vector<int>> ans;
            int n=intervals.size();
    
            if(intervals.size()==0)
            {
                ans.push_back(newInterval);
                return ans;
            }
    
    
            int k=0;
    
            while(k<n && newInterval[0]>=intervals[k][0])
            {
            
                ans.push_back(intervals[k]);
            
                k++;
            }
        
            if(k>0 && ans.back()[1]>=newInterval[0])
            {
                ans.back()[1]=max(ans.back()[1],newInterval[1]);
            }
            else
            {
                ans.push_back(newInterval);
            }
    
    
    
            while(k<n)
            {
                if(intervals[k][0]<=ans.back()[1])
                {
                    ans.back()[1]=max(intervals[k][1],ans.back()[1]);
                }
                else
                {
                    ans.push_back(intervals[k]);
                }
                k++;
            }
    
               return ans;
    

    
            
        }
    };