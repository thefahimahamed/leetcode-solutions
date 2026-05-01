class Solution {
public:
    bool isPalindrome(string s) 
    {
        
        string copy1;
        
        for(auto it : s)
        if(isalpha(it) || isdigit(it))
        {
          char ch = tolower(it);
          copy1.push_back(ch);
        }
        
        for(int i = 0; i < copy1.size()/2; i++)
        {
          if(copy1[i] != copy1[copy1.size()-i-1])
          return false;
        }
        return true;
        
    }
};