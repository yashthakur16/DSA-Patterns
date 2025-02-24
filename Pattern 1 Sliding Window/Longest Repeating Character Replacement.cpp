class Solution {
    public:
        int characterReplacement(string s, int k) 
        {
            int i=0;
            int j=0;
            int n=s.size();
            int maxCount=0;
            int size=0;
            
            vector<int> mpp(26,0);
    
            while(j<n)
            {
                mpp[s[j]-'A']++;
                maxCount=max(maxCount,mpp[s[j]-'A']);
    
                while(j-i+1-maxCount>k)
                {
                    mpp[s[i]-'A']--;
                    i++;
                }
    
                size=max(size,j-i+1);
    
                j++;
            }
    
            return size;
            
        }
    };