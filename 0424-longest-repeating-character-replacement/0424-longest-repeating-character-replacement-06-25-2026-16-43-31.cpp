class Solution {
public:
    int characterReplacement(string s, int k) {
        
    int l = 0; int r = 0;
    int ans = 0;
    int n = s.size();
    map < char , int > m;
    while(l < n && r < n)
    {
        int distance = r - l + 1;
        m[s[r]]++;
        int temp = 0;
        for(auto it: m)
        temp = max(temp,it.second);
        if(distance - temp > k)
        {
            m[s[l]]--;
            l++;
            distance -= 1;
        }
        ans = max(distance,ans);
        r++;
    }
    return ans;
    }
};