class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<pair<int, bool>> arr(n + 1, {0, false});

        int sizee = trust.size();

        for (int i = 0; i < sizee; i++) {
            
            // trust[i][1] is trusted by someone
            arr[trust[i][1]].first++;

            // trust[i][0] trusts someone
            arr[trust[i][0]].second = true;
        }

        for (int i = 1; i <= n; i++) {
            if (arr[i].first == n - 1 && arr[i].second == false) {
                return i;
            }
        }

        return -1;
    }
};