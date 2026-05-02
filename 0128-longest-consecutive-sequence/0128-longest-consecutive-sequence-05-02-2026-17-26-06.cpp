class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set < int > st;
        for(auto &it : nums)
        st.insert(it);

        int ans = 1;
        int cnt = 1;
        int last = *st.begin();
        for(auto &it : st)
        {
            if(it == last)
            continue;
            else if(abs(last-it) == 1)
            {
                cnt++;
                last = it;
                ans = max(cnt,ans);
            }
            else
            {
                cnt = 1;
                last = it;
            }
            
        }

        return ans;
    }
};