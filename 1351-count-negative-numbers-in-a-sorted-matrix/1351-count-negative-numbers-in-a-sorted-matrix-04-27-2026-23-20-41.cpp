class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
       
        int cnt = 0;
        for(auto &it : grid)
        {
            auto kt = upper_bound(it.begin(),it.end(),0,greater<int>());
            cnt += (it.end()-kt);
        }
        return cnt;

    }
};