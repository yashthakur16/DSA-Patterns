class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) 
        {
    
            int wordLen=words[0].size();
    
            int n=s.size();
    
            unordered_map<string,int> mpp;
    
            for(auto i : words)
            {
                mpp[i]++;
            }
    
            vector<int> ans;
    
            for(int i=0;i<wordLen;i++)
            {
                int left=i;
                int right=i;
                int count=0;
                unordered_map<string,int> temp;
    
                while(right<=n)
                {
                    string word=s.substr(right,wordLen);
                    right=right+wordLen;
                    
    
                    if(mpp.find(word)!=mpp.end())
                    {
                        count++;
                        temp[word]++;
    
                        while(temp[word]>mpp[word])
                        {
                            string newWord=s.substr(left,wordLen);
                            temp[newWord]--;
                            left=left+wordLen;
                            count--;
                        }
    
                        if(count==words.size())
                        {
                            ans.push_back(left);
                        }
                    }
                    else
                    {
                        left=right;
                        count=0;
                        temp.clear();
                    }
    
                    
                }
            }
    
            return ans;
            
        }
    };