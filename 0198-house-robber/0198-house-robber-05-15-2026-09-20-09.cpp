class Solution {
public:

vector<int> memo;
void solve(vector < int > &v, int i = 0, int sum = 0)
{
  if(memo[i] < sum)
  memo[i] = sum;
  else
  return;
  
  if(i >= v.size())
  return;
  
  solve(v,i+2,sum+v[i]);
  solve(v,i+1,sum);
  return;
}

    int rob(vector<int>& nums) {
      memo.assign(nums.size()+2, -1);
      solve(nums);
      int ans = 0;
      for(auto &it : memo)
      ans = max(ans,it);
      return ans;
    }
};