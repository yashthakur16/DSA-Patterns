int lengthOfLongestSubstring(string s) 
{
    int i=0;
    int j=0;
    int n=s.size();
    vector<int> v(26,0);
    int size=0;
    int unique=0;

    while(j<n)
    {
        v[s[j]-'a']++;
        if(v[s[j]-'a']==1) unique++;

        while(unique>2)
        {
            v[s[i]-'a']--;
            if(v[s[i]-'a']==0) unique--;
            i++; 
        }

        size=max(size,j-i+1);
        j++;
    }

    return size;

}
