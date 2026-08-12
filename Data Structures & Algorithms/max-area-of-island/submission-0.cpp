class Solution {
private:
    int res = 0;

    void bfs(int sr, int sc, vector<vector<int>>& grid, bool** visited) {
        int row = grid.size();
        int col = grid[0].size();
        int area = 0;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            area++;

            // Up
            if (r - 1 >= 0 &&
                grid[r - 1][c] == 1 &&
                !visited[r - 1][c]) {

                visited[r - 1][c] = true;
                q.push({r - 1, c});
            }

            // Down
            if (r + 1 < row &&
                grid[r + 1][c] == 1 &&
                !visited[r + 1][c]) {

                visited[r + 1][c] = true;
                q.push({r + 1, c});
            }

            // Left
            if (c - 1 >= 0 &&
                grid[r][c - 1] == 1 &&
                !visited[r][c - 1]) {

                visited[r][c - 1] = true;
                q.push({r, c - 1});
            }

            // Right
            if (c + 1 < col &&
                grid[r][c + 1] == 1 &&
                !visited[r][c + 1]) {

                visited[r][c + 1] = true;
                q.push({r, c + 1});
            }
        }

        res = max(res, area);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        bool** visited = new bool*[row];

        for (int i = 0; i < row; i++) {
            visited[i] = new bool[col]();
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                }
            }
        }

        for (int i = 0; i < row; i++) {
            delete[] visited[i];
        }

        delete[] visited;

        return res;
    }
};