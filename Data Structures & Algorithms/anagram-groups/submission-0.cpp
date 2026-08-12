class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string , vector<string>>bmap;
        for(auto &s: strs)
        {
            vector<int>freq(26 , 0);
            for(char c: s)
            {
                freq[c - 'a'] +=1;
            }
            string key;
            for(int x : freq)
            {
                key +=  to_string(x) +"#";
            }
            bmap[key].push_back(s);
        }
        vector<vector<string>>str;
        for(auto & x: bmap)
        str.push_back(x.second);
        return str;
    }
};
