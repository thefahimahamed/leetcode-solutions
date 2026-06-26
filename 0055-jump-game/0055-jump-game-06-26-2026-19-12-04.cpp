class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return true;
        
        
        int current = n-1;
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] >= current-i)
            current = i;
        }
        if(current == 0)
        return true;
        return false;
        
        
    }
};