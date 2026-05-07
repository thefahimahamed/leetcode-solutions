class Solution {
public:

unordered_map < long long , int > memo_cnt;
bool ans = false;
bool canReachTarget(int target, vector<int>& numbers, int cnt = 0, long long n = 0) 
{
    
    if (n == target) 
    {
        if(memo_cnt.find(n) != memo_cnt.end())
        memo_cnt[n] = min(cnt,memo_cnt[n]);
        else
        memo_cnt[n] = cnt;
        ans = true;
    return false;
    }
        
    if (n > target) return false;
    
    if(memo_cnt.find(n) != memo_cnt.end())
    {
        if(memo_cnt[n] <= cnt)
        return false;
        else
        memo_cnt[n] = cnt;
    }
    else
        memo_cnt[n] = cnt;
    

    for (auto &num : numbers) 
    {
        if (canReachTarget(target, numbers, cnt + 1, n + num))
        return false;
    }

    return false;
}


int coinChange(vector< int >& coins, int amount) 
{
    auto unique_iterator = unique(coins.begin(),coins.end());
    coins.erase(unique_iterator,coins.end());
    sort(coins.rbegin(),coins.rend());
    bool flag = canReachTarget(amount,coins);
    if(ans)
    return memo_cnt[amount];
    else
    return -1;
}
};