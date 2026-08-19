class Solution {
public:
    int countPrimes(int n) {
        vector < bool > is_prime(n+1,true);
        is_prime[0] = is_prime[1] = false;

        for(int i = 4; i <= n; i += 2)
        is_prime[i] = false;

        for(int i = 3; i*i <= n; i += 2)
        {
            if(is_prime[i])
            for(int j = i * i; j <= n; j += 2 * i)
            is_prime[j] = false;
        }

        int cnt = 0;
        for(int i = 0; i < n; i++)
        if(is_prime[i])
        cnt++;
        return cnt;
    }
};