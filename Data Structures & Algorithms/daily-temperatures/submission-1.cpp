class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>res;
        stack<int>s;
        res.push_back(0);
        s.push(arr.size() - 1);
        for(int i = arr.size() -2 ; i>=0; i--)
        {
            bool flag = false;
            while(!s.empty() && arr[i]>=arr[s.top()])
            {
                flag = true;
                s.pop();
            }
            int cal;
            if(flag)
             cal = (s.empty())? 0: s.top() - i;
            else
             cal = (s.empty())? 0: 1;
            s.push(i);
            res.push_back(cal);
        }
        reverse(res.begin() , res.end());
        return res;
    }
};
