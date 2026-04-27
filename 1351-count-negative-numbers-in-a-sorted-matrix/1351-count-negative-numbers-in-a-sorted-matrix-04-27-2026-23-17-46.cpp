class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
       
        int cnt = 0;
        for(auto &it : grid)
        {
            auto kt = upper_bound(it.begin(),it.end(),-1);
            if(*it.rbegin() < 0)
            cnt += (it.end()-kt);
            else
            cnt = 0;
        }
        return cnt;

    }
};