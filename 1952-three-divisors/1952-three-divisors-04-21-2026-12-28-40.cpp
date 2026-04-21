class Solution {
public:
    bool isThree(int n) {

        int result = sqrt(n);
        vector < int > v(result+1,0);
        for(int i = 1; i <= result; i++)
        {
            for(int j = i; j <= result; j += i)
            v[j]++;
        }

        if(v[result] == 2 && result*result == n)
        return true;
        else
        return false;
    }
};