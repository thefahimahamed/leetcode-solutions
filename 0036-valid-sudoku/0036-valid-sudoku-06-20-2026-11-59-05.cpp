class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i <= 6; i+=3)
        {
            for(int k = 0; k <= 6; k+=3)
            {
                unordered_set < char > s;
                for(int j = i; j < i+3; j++)
                {
                    for(int l = k; l < k+3; l++)
                    {
                        char temp = board[j][l];
                        if(isdigit(temp))
                        {
                        if(s.find(temp) != s.end())
                        return false;
                        else
                        s.insert(temp);
                        }
                    }
                }
            }
        }


        for(int i = 0; i <= 8; i++)
        {
            unordered_set < char > s1;
            unordered_set < char > s2;
            for(int j = 0; j <= 8; j++)
            {
                char temp1 = board[i][j];
                char temp2 = board[j][i];
                if(isdigit(temp1))
                {
                if(s1.find(temp1) != s1.end())
                return false;
                else
                s1.insert(temp1);
                }
                
                if(isdigit(temp2))
                {
                if(s2.find(temp2) != s2.end())
                return false;
                else
                s2.insert(temp2);
                }
            }
        }
        return true;
        
    }
};