class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector < int > ans(n,0);
        map < int,int > m;
        for(int i = n-1; i >= 0; i--)
        {
            m[v[i]] = i;
            auto it = m.upper_bound(v[i]);
            if(it == m.end())
            continue;
            int dis = INT_MAX;
            for(auto j = it; j != m.end(); j++)
            {
                int index = j->second;
                dis = min(index - i,dis);
            }
            ans[i] = dis;
        }
        return ans;
    }
};