class Solution {
public:
    int countDigits(int num) {
        
        vector < int > v;
        int temp = num;
        while(temp)
        {
            v.push_back(temp % 10);
            temp /= 10;
        }
        int cnt = 0;
        for(auto it : v)
        if(num % it == 0)
        cnt++;

        return cnt;
    }
};