class Solution {
public:

int numDecodings(string s) {
        vector<vector<bool>> v(10, vector<bool>(10, false));
        for(int i = 1; i <= 2; i++)
        {
            for(int j = 0; j <= 9; j++)
            {
                v[i][j] = true;
                if(i == 2 && j == 6)
                break;
            }
        }

        
        string cpy = "";
        int cnt = 0;
        for(auto &it : s)
        {
            if(it == '0')
            cnt = 1;
            else if(cnt == 1)
            cnt--;
            else
            cpy += it;
        }
        int n = s.size();
        if((int)cpy.size() == 0)
        return 0;
        cnt = 0;
        vector < int > dp(n+1);
        dp[n] = 1;
        if(s[n-1]!= '0')
        dp[n-1] = 1;
        else
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--)
        {
            int x = s[i] - '0';
            int y = s[i+1] - '0';
            if(v[x][y])
            {
            if(cnt & 1)
            dp[i] = dp[i+1];
            else
            dp[i] = dp[i+1] + dp[i+2];
            cnt = max(0,cnt-1);
            }
            else if(x == 0)
            {
              dp[i] = 0;
              cnt = 2;
            }
            else
            {
            dp[i] = dp[i+1];
            cnt = max(0,cnt-1);
            }
            
        }
        return dp[0];
    }
};