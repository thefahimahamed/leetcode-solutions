class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector < int > v = nums;
    sort(nums.begin(),nums.end());
    vector < int > ans;
    pair < int , int > p;
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
    long long sum = (nums[l] + nums[r]);
    if(sum == target)
    {
    p.first = nums[l];
    p.second = nums[r];
    break;
    }
    else if(sum > target)
    r--;
    else
    l++;
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(ans.size() == 2)
        break;

        if(v[i] == p.first)
        {
        ans.push_back(i);
        continue;
        }
        if(v[i] == p.second)
        {
        ans.push_back(i);
        continue;
        }
    }
    return ans;
}
};