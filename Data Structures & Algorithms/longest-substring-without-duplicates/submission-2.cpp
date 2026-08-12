class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char>q;
        unordered_set<char>arr;
        int res = 0;
        for(int i = 0 ;i< s.length() ; i++)
        {
            int le = 0;
            if(arr.count(s[i]))
            {
                while(q.front()!=s[i])
                {
                    int x = q.front();
                    q.pop();
                    arr.erase(x);
                }
                q.pop();
                arr.erase(s[i]);
            }
                q.push(s[i]);
                le = q.size();
                res = max(res , le);
                arr.insert(s[i]);
        }
        return res;
    }
};
