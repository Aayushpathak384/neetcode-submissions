class Solution {
private:

    void bfs(vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             queue<tuple<int, int, int>>& q) {

        int row = grid.size();
        int col = grid[0].size();

        while (!q.empty()) {

            auto [r, c, count] = q.front();
            q.pop();

            // Up
            if (r - 1 >= 0 &&
                grid[r - 1][c] > 0 &&
                !visited[r - 1][c]) {

                grid[r - 1][c] = count + 1;
                visited[r - 1][c] = true;
                q.push({r - 1, c, count + 1});
            }

            // Down
            if (r + 1 < row &&
                grid[r + 1][c] > 0 &&
                !visited[r + 1][c]) {

                grid[r + 1][c] = count + 1;
                visited[r + 1][c] = true;
                q.push({r + 1, c, count + 1});
            }

            // Left
            if (c - 1 >= 0 &&
                grid[r][c - 1] > 0 &&
                !visited[r][c - 1]) {

                grid[r][c - 1] = count + 1;
                visited[r][c - 1] = true;
                q.push({r, c - 1, count + 1});
            }

            // Right
            if (c + 1 < col &&
                grid[r][c + 1] > 0 &&
                !visited[r][c + 1]) {

                grid[r][c + 1] = count + 1;
                visited[r][c + 1] = true;
                q.push({r, c + 1, count + 1});
            }
        }
    }

public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(
            row, vector<bool>(col, false)
        );

        queue<tuple<int, int, int>> q;

        // Put ALL treasures into the queue
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 0) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        // One BFS for all treasures
        bfs(grid, visited, q);
    }
};