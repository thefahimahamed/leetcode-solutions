class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int ans = *max_element(piles.begin(),piles.end());
        int r = ans;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(auto &it : piles)
            {
            cnt += ((it + mid - 1)/mid);
            if(cnt > h)
            break;
            }
            if(cnt > h)
            l = mid + 1;
            else
            {
                ans = min(mid,ans);
                r = mid - 1;
            }
            
        }
        return ans;
    }
};