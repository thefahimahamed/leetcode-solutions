class Solution {
public:
    string longestPalindrome(string s) {
      string ans_string = "";
      int n = s.size();
      vector < vector < bool > > dp(n, vector < bool > (n,false));
      for(int i = n-1; i >= 0; i--)
      {
        for(int j = i; j < n; j++)
        {
          if(i == j)
          dp[i][j] = true;
          else if(j == i + 1 && s[i] == s[j])
          dp[i][j] = true;
          else
          {
            if(dp[i+1][j-1] && s[i] == s[j])
            dp[i][j] = true;
          }
        }
      }
      int mx = 0;
      int left = 0, right = 0;
      for(int i = 0; i < dp.size(); i++)
      {
        for(int j = 0; j < dp.size(); j++)
        {
          if(dp[i][j])
          {
            int diff = abs(i-j);
            if(diff > mx)
            {
              mx = diff;
              left = i; right = j;
            }
          }
        }
      }
      ans_string = s.substr(left,right-left+1);
      return ans_string;
    }
};