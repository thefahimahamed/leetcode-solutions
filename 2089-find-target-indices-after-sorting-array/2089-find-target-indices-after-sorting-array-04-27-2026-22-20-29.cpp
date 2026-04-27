class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        auto it = lower_bound(v.begin(),v.end(),target);
        auto jt = upper_bound(v.begin(),v.end(),target);
        vector < int > ans;
        for(int i = it-v.begin(); i < jt-v.begin(); i++)
        ans.push_back(i);
        
        return ans;
    }
};