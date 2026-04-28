class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector < int > freq_s(256+1,0);
        vector < int > freq_t(256+1,0);

        for(auto it : s)
        freq_s[(int)it]++;

        for(auto it : t)
        freq_t[(int)it]++;

        bool flag = true;

        for(auto it : s)
        {
            if(freq_s[(int)it] != freq_t[(int)it])
            {
                flag = false;
                break;
            }
        }
        for(auto it : t)
        {
            if(freq_s[(int)it] != freq_t[(int)it])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        return true;
        else
        return false;
    }
};