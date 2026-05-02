class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        set < int > st;
        for(auto &it : nums)
        st.insert(it);

        if(st.size() == 0)
        return 0;
        
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
                
            }
            else
            {
                cnt = 1;
                last = it;
            }
            ans = max(cnt,ans);
        }

        return ans;
    }
};