class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
       
        int cnt = 0;
        for(auto &it : grid)
        {
            sort(it.begin(),it.end());
            auto kt = upper_bound(it.begin(),it.end(),-1);
            cnt += (kt-it.begin());
        }
        return cnt;

    }
};