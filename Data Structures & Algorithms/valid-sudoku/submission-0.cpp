class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {

        int n = arr.size();
        int m = arr[0].size();
        //check for row
        for(int i = 0 ; i< n ; i++)
        {
            unordered_set<char>s;
            for(int j = 0 ; j< m ; j++)
            {
                if(arr[i][j]=='.')
                continue;
                else
                {
                    if(s.count(arr[i][j]))
                    return false;
                    else
                    s.insert(arr[i][j]);
                }
            }
        }
        //check for coloum 
        for(int j = 0 ; j< m ; j++)
        {
            unordered_set<char>s;
            for(int i = 0 ; i< n ; i++)
            {
                if(arr[i][j]=='.')
                continue;
                else
                {
                    if(s.count(arr[i][j]))
                    return false;
                    else
                    s.insert(arr[i][j]);
                }
            }
        }
        int block = 0;
        int coll = 0;
        int row = 0;
        while(block<9)
        {
            unordered_set<char>s;
            if(block %3 == 0 && block!=0)
            {
                row +=3;
                coll  = 0;
            }
            for(int i = 0 + row ; i< 3 + row ; i++)
            {
                for(int j = 0 + coll ; j<3 + coll ; j++)
                {
                    if(arr[i][j]=='.')
                    continue;
                    else
                    {
                        if(s.find(arr[i][j])!=s.end())
                        return false;
                        else
                        s.insert(arr[i][j]);
                    }
                }
            }
            s.clear();
            block++;
            coll += 3;
        }
        return true;
    }
};
