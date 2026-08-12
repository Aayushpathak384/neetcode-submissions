class Solution {
public:
    vector<int>store;
    string encode(vector<string>& strs) {
        string ptr = "";
        for(string &x : strs)
        {
            store.push_back(x.length());
            ptr +=x;
        }
        return ptr;
    }

    vector<string> decode(string s) {
        vector<string> ptr;
        int i = 0;
        for(int x: store)
        {
            string str = "";
            for(int j = i ; j< x+i; j++)
            {
                str +=s[j];
            }
            ptr.push_back(str);
            i +=x;
        }
        return ptr;
    }
};
