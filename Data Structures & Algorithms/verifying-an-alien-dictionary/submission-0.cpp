class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char , int>mp;
        int count = 0;
        for(char s : order){
            mp[s] = count;
            count++;
        }

        int n = words.size();

        for(int i = 0 ; i< n - 1 ; i++)
        {
            int size_a = words[i].length();
            int size_b = words[i + 1].length();
            int j = 0 ;
            int ra = mp[words[i][j]];
            int rb = mp[words[i +  1][j]];
            while(j< size_a && j< size_b && ra == rb)
            {
                j++;
                ra = mp[words[i][j]];
                rb = mp[words[i +  1][j]];
            }
            if(ra< rb) continue;
            else return false;
            if(size_a > size_b) return false;
        }

        return true;
    }
};