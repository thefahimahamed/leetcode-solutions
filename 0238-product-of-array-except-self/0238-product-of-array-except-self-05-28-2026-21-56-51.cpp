class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        int mul = 1;
        for(auto it : nums)
        {
            if(it != 0)
            mul *= it;
            if(it == 0)
            zero++;
        }
        vector < int > ans;
        if(zero > 1)
        {
            for(auto &it : nums)
            ans.push_back(0);
        }
        else if(zero == 1)
        {
            for(auto &it : nums)
            if(it == 0)
            ans.push_back(mul);
            else
            ans.push_back(0);
        }
        else
        {
            for(auto &it : nums)
            ans.push_back(mul/it);
        }
        return ans;
    }
};