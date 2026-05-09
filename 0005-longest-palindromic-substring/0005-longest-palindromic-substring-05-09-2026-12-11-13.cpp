class Solution {
public:

string ans = "";
int mx = 0;
void expand(string s, int left, int right) 
{
    while (left >= 0 && right < s.size() && s[left] == s[right]) 
    {
        left--;
        right++;
        if(left == -1 || right == s.size())
        break;
    }
    string temp = s.substr(left+1,right-left-1);
    if(mx < temp.size())
    {
        mx = temp.size();
        ans = temp;
    }
    return;
}
    string longestPalindrome(string s) {
      for (int i = 0; i < s.size(); i++) 
      {
        expand(s, i, i);
        expand(s, i, i + 1);
      }
      return ans;
    }
};