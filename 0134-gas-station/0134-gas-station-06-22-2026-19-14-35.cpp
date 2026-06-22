class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
    long long sum_gas = accumulate(gas.begin(),gas.end(),0);
    long long sum_cost = accumulate(cost.begin(),cost.end(),0);
    if(sum_cost > sum_gas)
    return -1;
    int n = gas.size();
    for(int mid = 0; mid < n; mid++)
    {
        long long one = 0;
        long long two = 0;
        bool flag = true;
        for(int i = mid; i < mid+n; i++)
        {
            int index = (i) % n;
            one += gas[index];
            two += cost[index];
            if(two > one)
            {
                flag = false;
                mid = i;
                break;
            }
        }
        if(flag)
        return mid;
    }
    return -1;
    }
};