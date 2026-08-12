class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int > m , p ;
        int n = s.length();
        int z = t.length();
        if(n!=z) return false;
        for(int i = 0 ; i< n ; i++)
        {
            m[s[i]]++;
            p[t[i]]++;
        }
        for(const auto &x:m )
        {
            char key = x.first;
            int val = x.second;
            if(!p.count(key) || p.at(key)!=val)
            return false;
        }
        return true;
    }
};
