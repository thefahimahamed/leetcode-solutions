class Solution {
public:
static bool cmp(pair < char , int > &a, pair < char , int > &b)
{
    if(a.second > b.second)
    return true;
    
    return false;
}
int leastInterval(vector<char>& tasks, int n) {
    unordered_map < char,int > m1;
    for(auto &it : tasks)
    m1[it]++;
    vector < pair < char , int > > vp(m1.begin(),m1.end());
    sort(vp.begin(),vp.end(),cmp);
    int total = tasks.size();
    int ans = 0;
    while(total > 0)
    {
        int tracker = n+1;
        int done_tasks = 0;
        for(auto &it : vp)
        {
            if(tracker == 0)
            break;
            
            if(it.second > 0)
            {
            tracker--;
            it.second--;
            total--;
            done_tasks++;
            }
        }
        sort(vp.begin(),vp.end(),cmp);
        if(total > 0)
        ans += (n+1);
        else
        ans += done_tasks;
    }
    return ans;
    }
};