class Solution {
public:
    int jump(vector<int>& nums) {
        deque < pair < int, int > > s;
        int n = nums.size()-1;
        if(nums.size() == 1)
        return 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(nums[i] > 1)
            {
                int temp = nums[i] + i;
                if(!s.empty())
                while(s.back().first <= temp)
                {
                s.pop_back();
                if(s.empty())
                break;
                }
                if(s.empty())
                s.push_back({min(temp,n),i});
                else
                s.push_back({min(temp,s.back().second),i});
            }
            else
            {
                if(nums[i] > 0)
                s.push_back({i+1,i});
            }
        }
        int ans = s.size();
        return ans;   
    }
};