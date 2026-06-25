class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map < int , int > m;
        for(auto &it : nums)
        m[it]++;
        if(m.find(0) != m.end() && m.size() == 1)
        {
            vector < int > v = {0,0,0};
            vector< vector < int > > ans;
            ans.push_back(v);
            return ans;
        }
        set < vector < int > > st;
        sort(nums.begin(),nums.end());
        int mn = nums.front();
        int mx = nums.back();
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = n-1; j > i; j--)
            {
                int sum = (nums[i] + nums[j]);
                int need = sum*-1;
                if(need > mx && need > 0)
                break;
                if(m.find(need) == m.end())
                continue;

                vector < int > temp = {need,nums[i],nums[j]};
                if(need != nums[i] || nums[j] != need) 
                sort(temp.begin(),temp.end());
                if(nums[i] == need && need == nums[j] && m[need] < 3)
                continue;
                else if((nums[i] == need || nums[j] == need) && m[need] < 2)
                continue;
                else
                st.insert(temp);
            }
        }
        vector< vector < int > > ans;
        for(auto &it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};