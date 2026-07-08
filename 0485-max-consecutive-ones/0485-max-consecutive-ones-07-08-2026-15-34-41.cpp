class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int cnt = 0;
        int ans = 0;
        for(auto &it : nums)
        if(it == 1)
        cnt++;
        else
        {
        ans = max(cnt,ans);
        cnt = 0;
        }
        ans = max(cnt,ans);
        return ans;
        
    }
};