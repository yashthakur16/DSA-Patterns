class Solution {
    public:
        int totalFruit(vector<int>& fruits) 
        {
            int i=0;
            int j=0;
            int n=fruits.size();
            int unique=0;
            int size=0;
    
            vector<int> v(n,0);
    
            while(j<n)
            {
                v[fruits[j]]++;
                if(v[fruits[j]]==1) unique++;
    
                while(unique>2)
                {
                    v[fruits[i]]--;
                    if(v[fruits[i]]==0) unique--;
                    i++;
                }
    
                size=max(size,j-i+1);
                j++;
            }
    
            return size;
        }
    };