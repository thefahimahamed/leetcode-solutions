class Solution {
public:
    int maxProfit(vector<int>& prices){
  int ans = 0;
  int value = *prices.begin();
  for(int i = 1; i < prices.size(); i++)
  {
    if(prices[i] < prices[i-1])
    value = min(value,prices[i]);
    int diff = prices[i]-value;
    ans = max(diff,ans);
  }
  return ans;
}

};