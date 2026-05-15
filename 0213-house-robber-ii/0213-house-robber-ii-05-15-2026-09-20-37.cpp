class Solution {
public:
vector<int> memo;
void solve(vector < int > &v, int i = 0, int sum = 0)
{
  if(i >= v.size())
  return;

  
  if(memo[i] < sum + v[i])
  memo[i] = sum + v[i];
  else
  return;
  

  solve(v,i+2,sum+v[i]);
  solve(v,i+1,sum);
  return;
}

    int rob(vector<int>& nums) {
      if(nums.size() == 1)
      return nums[0];
      vector<int> excludeLast(nums.begin(), nums.end() - 1);
      memo.assign(excludeLast.size(), 0);
      solve(excludeLast);
      int ans = 0;
      for(auto &it : memo)
      ans = max(ans,it);
      vector<int> excludeFirst(nums.begin() + 1, nums.end());
      memo.assign(excludeFirst.size(), 0);
      solve(excludeFirst);
      for(auto &it : memo)
      ans = max(ans,it);
      return ans;
    }
};