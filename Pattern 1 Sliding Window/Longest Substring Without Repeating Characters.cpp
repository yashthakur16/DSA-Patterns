class Solution {
    public:
        int lengthOfLongestSubstring(string s) 
        {
            int i=0;
            int j=0;
            int n=s.size();
            int size=0;
    
            unordered_map<char,int> mpp;
    
            while(j<n)
            {
                if(mpp.find(s[j])!=mpp.end())
                {
                    i=max(mpp[s[j]]+1,i);
                }
    
                mpp[s[j]]=j;
                size=max(size,j-i+1);
                j++;
    
            }
    
            return size;
        }
    };