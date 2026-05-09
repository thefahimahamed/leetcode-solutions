class Solution {
public:
    int maxProfit(vector<int>& prices){
  int ans = 0;
  int value = *prices.begin();
  int profit = 0;
  for(int i = 1; i < prices.size(); i++)
  {
    if(prices[i] < prices[i-1])
    {
    ans += profit;
    profit = 0;
    value = prices[i];
    }
    int diff = prices[i]-value;
    profit = max(diff,profit);
  }
  ans += profit;
  
  return ans;
}
};