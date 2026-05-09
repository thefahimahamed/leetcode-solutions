class Solution {
public:


long long expand(string s, int left, int right) 
{
    long long cnt = 0;
    while (left >= 0 && right < s.size() && s[left] == s[right]) 
    {
        cnt++;
        left--;
        right++;
        if(left == -1 || right == s.size())
        break;
    }
    return cnt;
}
    int countSubstrings(string s) {
      long long cnt = 0;
      for (int i = 0; i < s.size(); i++) 
      {
        long long odd = expand(s, i, i);
        cnt += odd;
        long long even = expand(s, i, i + 1);
        cnt += even;
      }
      return cnt;
    }
};