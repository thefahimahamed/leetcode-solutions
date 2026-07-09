class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = 0;
        
        for(auto &it : sentences)
        {
            string &temp = it;
            string max_word = "";
            int cnt = 0;
            for(auto &kt : temp)
            {
                if(isalpha(kt))
                    max_word += kt;
                else if(kt == ' ' && max_word.empty())
                    continue;
                else
                {
                    max_word.erase();
                    cnt++;
                }
            }
            if(!max_word.empty())
            cnt++;
            mx = max(cnt,mx);
        }
        return mx;
        
    }
};