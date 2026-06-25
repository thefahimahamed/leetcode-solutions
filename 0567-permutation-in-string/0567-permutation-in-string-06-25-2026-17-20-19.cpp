class Solution {
public:
    bool checkInclusion(string s1, string s2) 
{

        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2)
        return false;

        int l = 0;
        int r = n1-1;
        unordered_map < char , int > m;
        unordered_map < char , int > m1;
        for(int i = 0; i < n1-1; i++)
        m[s2[i]]++;
        for(int i = 0; i < n1; i++)
        m1[s1[i]]++;
        while(l <= n2-n1)
        {
            m[s2[r]]++;
            bool flag = true;
            for(auto it : m1)
            {
            char ch = it.first;
                if(m[ch] != m1[ch])
                {
                    m[s2[l]]--;
                    l++; r++;
                    flag = false;
                    break;
                }
            }
            if(flag)
            return true;
        }
        return false;
    }
};