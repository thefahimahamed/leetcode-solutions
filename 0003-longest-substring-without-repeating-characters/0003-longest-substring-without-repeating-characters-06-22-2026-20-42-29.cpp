class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set < char > st;
        int l = 0; int n = s.size();
        int r = 0;
        while(l < n &&  r < n)
        {
            if(st.empty() && r < n)
            {
                st.insert(s[r]);
                ans = max((int)st.size(),ans);
                r++;
            }
            else if(r < n)
            {
                char ch = s[r];
                if(st.find(ch) != st.end())
                {
                    if(s[l] == ch)
                    {
                    r++;
                    l++;
                    continue;
                    }
                    else
                    st.erase(s[l]);
                    l++;
                }
                else
                {
                    st.insert(s[r]);
                    ans = max((int)st.size(),ans);
                    r++;
                }
            }
        }
        return ans;
        
    }
};