class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        for(int i = 0 ; i< n ; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else if(!st.empty())
            {
                char x = s[i];
                if(x == ')')
                {
                    if(st.top()!='(')
                    return false;
                }
                else if(x == '}')
                {
                    if(st.top()!='{')
                    return false;
                }
                else
                {
                    if(st.top()!='[')
                    return false;
                }
                st.pop();
            }
            else
            return false;
        }
        if(!st.empty())
        return false;
        else
        return true;
    }
};
