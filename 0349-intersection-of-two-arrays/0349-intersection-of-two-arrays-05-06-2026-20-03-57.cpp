class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map < int , int > m;
        
        vector< int > ans;
        for(auto &it : nums1)
            m[it] = 1;
        for(auto &it : nums2)
            if(m[it] == 1)
            {
                ans.push_back(it);
                m[it] = 0;
            }

        return ans;
    }
};