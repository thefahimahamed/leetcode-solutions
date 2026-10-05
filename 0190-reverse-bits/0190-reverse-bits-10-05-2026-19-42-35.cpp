class Solution {
public:
    int reverseBits(int n) {
        int ans = 0LL;
        for(int i = 0; i < 32; i++)
        {
            ans = ans << 1;
            if(n & 1)
            ans += 1;
            n = n >> 1;
        }
        return ans;
    }
};