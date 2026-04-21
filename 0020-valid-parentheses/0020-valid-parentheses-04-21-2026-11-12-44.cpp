class Solution {
public:
    bool isValid(string s) {
        stack < char > st;
        for(auto it : s)
        {
                if(st.empty())
                st.push(it);
                else if(it == '(' || it == '{' || it == '[')
                st.push(it);
                else if(st.top() == '(' && it == ')')
                st.pop();
                else if(st.top() == '{' && it == '}')
                st.pop();
                else if(st.top() == '[' && it == ']')
                st.pop();
                else
                st.push(it);
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};