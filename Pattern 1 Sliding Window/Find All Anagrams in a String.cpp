class Solution {
    public:
        vector<int> findAnagrams(string s, string p) 
        {
            int window=p.size();
            int n=s.size();
    
            if(n<window)
            {
                return {};
            }
    
            vector<int> ans;
    
            vector<int> arr1(26,0);
            vector<int> arr2(26,0);
    
            for(int i=0;i<window;i++)
            {
                arr1[p[i]-'a']++;
                arr2[s[i]-'a']++;
            }
    
            if(arr1==arr2) ans.push_back(0);
    
            int j=window;
            int i=0;
    
            while(j<n)
            {
                arr2[s[i++]-'a']--;
                arr2[s[j++]-'a']++;
    
                if(arr2==arr1) ans.push_back(i);
            }
    
            return ans;
            
        }
    };