class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size()-1;
        int ans = nums.back();
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] > ans)
            l = mid + 1;
            else
            {
                ans = min(ans,nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
        
    }
};