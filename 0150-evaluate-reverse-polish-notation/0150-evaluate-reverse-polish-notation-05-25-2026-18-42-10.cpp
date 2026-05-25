class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack < long long > st;
        unordered_set < string > s = {"+","-","*","/"};
        for(auto &it : tokens)
        {
            string temp = it;
            if(s.find(temp) == s.end())
            {
                reverse(temp.begin(),temp.end());
                bool minus = false;
                long long total = 0;
                if(temp.back() == '-')
                {
                    minus = true;
                    temp.pop_back();
                }
                for(long long i = 0; i < temp.size(); i++)
                {
                    long long value = temp[i] - '0';
                    total += (value*pow(10LL,i));
                }
                if(minus)
                total *= -1LL;
                st.push(total);
            }
            else
            {
                long long y = st.top(); st.pop();
                long long x = st.top(); st.pop();
                long long ans;
                if(it == "/")
                ans = x/y;
                else if(it == "-")
                ans = x-y;
                else if(it == "+")
                ans = x+y;
                else
                ans = x*y;
                st.push(ans);
            }
        }

        return st.top();
    }
};