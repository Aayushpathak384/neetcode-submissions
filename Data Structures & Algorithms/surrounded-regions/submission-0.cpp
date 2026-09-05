class Solution {
    private:
     void bfs(vector<vector<char>>& grid,  int i , int j , vector<vector<bool>>&visited ){

        int row = grid.size();
        int col = grid[0].size();

        visited[i][j] = true;

        queue<pair<int , int>>q;
        q.push({i , j});

        while (!q.empty()) {

            
                auto [r, c] = q.front();
                q.pop();
                

                // UP
                if (r - 1 >= 0 && grid[r - 1][c] == 'O' && !visited[r - 1][c]) {
                    visited[r - 1][c] = true;
                    q.push({r - 1, c});
                }

                // DOWN
                if (r + 1 < row && grid[r + 1][c] == 'O' && !visited[r + 1][c]) {
                    visited[r + 1][c] = true;
                    q.push({r + 1, c});
                }

                // LEFT
                if (c - 1 >= 0 && grid[r][c - 1] == 'O' && !visited[r ][c - 1]) {
                    visited[r][c - 1] = true;
                    q.push({r, c - 1});
                }

                // RIGHT
                if (c + 1 < col && grid[r][c + 1] == 'O' && !visited[r][c + 1]) {
                    visited[r][c + 1] = true;
                    q.push({r, c + 1});
                }
            

           
        }
    }
public:
    void solve(vector<vector<char>>& arr) {
        
        int row = arr.size();
        int coll = arr[0].size();

        vector<vector<bool>> visited(row, vector<bool>(coll, false));
        // travel to border element

        for(int i = 0 ; i< coll ; i++)
        if(arr[0][i] == 'O' && !visited[0][i])
        bfs(arr , 0 , i , visited);

        for(int i = 0 ; i< row ; i++)
        if(arr[i][0] == 'O' && !visited[i][0])
        bfs(arr , i , 0 , visited);

        for(int i = 0 ; i< coll ; i++)
        if(arr[row - 1][i] == 'O' && !visited[row - 1][i])
        bfs(arr , row - 1 , i , visited);

        for(int i = 0 ; i< row ; i++)
        if(arr[i][coll - 1] == 'O' && !visited[i][coll - 1])
        bfs(arr , i , coll - 1 , visited);

        //for all o which are not visited mark them as x
        for(int i = 0 ; i< row ; i++)
        {
            for(int j = 0 ; j< coll ; j++)
            {
                if(arr[i][j] == 'O' && !visited[i][j])
                arr[i][j] = 'X';
            }
        }
    }
};
