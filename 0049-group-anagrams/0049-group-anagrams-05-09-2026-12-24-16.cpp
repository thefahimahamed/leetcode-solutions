class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector < vector < string >> v;
    unordered_map < string, vector < string > > m;
        int index = 0;
        for(auto it : strs)
            {
            string temp = it;
            sort(temp.begin(),temp.end());
            m[temp].push_back(it);
            }
        for(int i = strs.size()-1; i >= 0; i--)
            {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            auto it = m.find(temp);
            if(it == m.end())
            continue;
            v.push_back(m[temp]);
            m.erase(it);
            }
            return v;
    }
};