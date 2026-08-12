class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int pre[n] , next[n];
        stack<int>s;
        int res;
        for(int i = n -1 ; i>=0 ; i--)
        {
            while(!s.empty() && arr[i]<=arr[s.top()])
            {
                s.pop();
            }
            next[i] = (s.empty())?n:s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }

        
        for(int i = 0 ; i< n; i++)
        {
            while(!s.empty() && arr[i]<=arr[s.top()])
            {
                s.pop();
            }
            pre[i] = (s.empty())?-1:s.top();
            s.push(i);
            int width = next[i] - pre[i]- 1;
            int area = arr[i]*width;
            res = max(res , area);
        }
        return res;

        
    }
};
