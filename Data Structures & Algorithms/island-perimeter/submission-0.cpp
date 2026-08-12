class Solution {
private:
    int peri = 0;

    void check_border(vector<vector<int>>& arr, int r, int c, int row, int col)
    {
        if(r == 0 || arr[r-1][c] == 0) peri++;
        if(r == row-1 || arr[r+1][c] == 0) peri++;
        if(c == 0 || arr[r][c-1] == 0) peri++;
        if(c == col-1 || arr[r][c+1] == 0) peri++;
    }

    void papa(vector<vector<int>>& arr,
              vector<vector<bool>>& visited,
              int r,
              int c,
              int row,
              int col)
    {
        queue<pair<int,int>> q;

        q.push({r,c});
        visited[r][c] = true;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            r = cur.first;
            c = cur.second;

            check_border(arr,r,c,row,col);

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<row &&
                   nc>=0 && nc<col &&
                   !visited[nr][nc] &&
                   arr[nr][nc]==1)
                {
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    }

public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row,
                                     vector<bool>(col,false));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                    papa(grid,visited,i,j,row,col);
            }
        }

        return peri;
    }
};