class Solution {
    public:
        bool checkInclusion(string s1, string s2) 
        {
    
            if(s2.size()<s1.size()) return false;
    
            vector<int> s1A(26,0);
            vector<int> s2A(26,0);
    
            for(int i=0;i<s1.size();i++)
            {
                s1A[s1[i]-'a']++;
                s2A[s2[i]-'a']++;
            } 
    
            if(s1A==s2A) return true;
    
            int i=0;
            int j=s1.size();
            int n=s2.size();
    
            while(j<n)
            {
                s2A[s2[i++]-'a']--;
                s2A[s2[j++]-'a']++;
    
                if(s1A==s2A) return true;
            }
    
            return false;
    
            
        }
    };