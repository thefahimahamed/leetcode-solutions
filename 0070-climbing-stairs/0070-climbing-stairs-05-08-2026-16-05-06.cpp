class Solution {
public:

vector<int> memo = vector<int>(46, 0);
Solution() 
{
    memo[1] = 1;
    memo[2] = 2;
        
}
int solve(int n)
{
    if(n == 3)
    return memo[n] = memo[1] + memo[2];

    return memo[n] = solve(n-1) + memo[n-2];
}
    int climbStairs(int n) 
    {
        if(n <= 2)
        return n;
        else
        return solve(n); 
    }
};