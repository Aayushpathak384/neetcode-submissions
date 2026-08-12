class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>s;
        for(int i = 0 ; i< n ; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i]== "/")
            {
                int x= s.top();
                s.pop();
                int y = s.top();
                s.pop();
                int cal;
                if(tokens[i]=="+")
                {
                    cal = x + y;
                }
                else if(tokens[i] == "-")
                {
                    cal = y - x;
                }
                else if(tokens[i] == "*")
                {
                    cal = x*y;
                }
                else
                cal = y/x;
                s.push(cal);
            }
            else
            s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};
