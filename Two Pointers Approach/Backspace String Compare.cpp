class Solution {
    public:
        bool backspaceCompare(string s, string t) 
        {
            int i=s.size()-1;
            int j=t.size()-1;
    
            int iBack=0;
            int jBack=0;
    
            while(i>=0 || j>=0)
            {
                while((i>=0)&&(iBack!=0 || s[i]=='#'))
                {
                    if(s[i]=='#')
                    {
                        iBack++;
                    }
                    else
                    {
                        iBack--;
                    }
                    i--;
                }
    
                while((j>=0)&&(jBack!=0 || t[j]=='#'))
                {
                    if(t[j]=='#')
                    {
                        jBack++;
                    }
                    else
                    {
                        jBack--;
                    }
                    j--;
                }
    
                if (i >= 0 && j >= 0) 
                {
                    if (s[i] != t[j]) return false;
                    i--;
                    j--;
                }
                else if (i >= 0 || j >= 0) 
                {
                    return false;
                }
    
            }
    
    
            return true;
        }
    };