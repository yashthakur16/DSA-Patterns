class Solution {
    public:
        string minWindow(string s, string t) 
        {
            
            unordered_map<char,int> mpp;
    
            int n=s.size();
            if(n<t.size())
            {
                return "";
            }
    
            int matches=0;
    
            for(auto i : t)
            {
                mpp[i]++;
                if(mpp[i]==1) matches++;
            }
    
            int i=0;
            int j=0;
            int start=-1;
            int size=INT_MAX;
    
            while(j<n)
            {
                
    
                if(mpp.find(s[j])!=mpp.end())
                {
                    mpp[s[j]]--;
                    if(mpp[s[j]]==0) matches--;
                }
    
                
                while(matches==0)
                {
                    if(size>j-i+1)
                    {
                        start=i;
                        size=j-i+1;
                    }
                    if(mpp.find(s[i])!=mpp.end())
                    {
                        mpp[s[i]]++;
                        if(mpp[s[i]]>0) matches++;
                    }
                    i++;
                }
    
                j++;
    
    
            }
    
            return start==-1 ? "":s.substr(start,size);
        }
    };