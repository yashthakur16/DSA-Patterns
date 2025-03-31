
#include <algorithm>
vector<int> findFreeIntervals(vector<vector<int>> &schedules) 
{
    vector<vector<int>> v;

    for(auto schedule : schedules)
    {
        for(int i=0;i<schedule.size();i+=2)
        {
            v.push_back({schedule[i],schedule[i+1]});
        }
    }

    sort(v.begin(),v.end());

    vector<vector<int>> ans;

    ans.push_back(v[0]);

    for(int i=1;i<v.size();i++)
    {
        if(ans.back()[1]+1>=v[i][0])
        {
            ans.back()[1]=max(ans.back()[1],v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }

    vector<int> interval;
    int i=0;

    if(ans[i][0]==0)
    {
        if(ans[i][1]==100000000)
        {
            return {};
        }
        else
        {
            interval.push_back(ans[i][1]+1);
            i++;
        }
    }
    else
    {
        interval.push_back(0);
    }

    while(i<ans.size())
    {
        interval.push_back(ans[i][0]-1);

        if(i<ans.size()&&ans[i][1]!=100000000)
        {
            interval.push_back(ans[i][1]+1);
            
        }
        i++;
        
    }

    if(ans.back()[1]!=100000000)
    {
        interval.push_back(100000000);
    }

    return interval;
  
}