class Solution {
public:
    bool isHappy(int n) {
        unordered_set < int > s;
        s.insert(n);
        while(n > 1)
        {
            int temp = n;
            n = 0;
            while(temp)
            {
                int rem = temp % 10;
                rem *= rem;
                n += rem;
                temp/= 10;
            }
            if(s.find(n) != s.end())
            return false;
            s.insert(n);
        }
        return true;
    }
};