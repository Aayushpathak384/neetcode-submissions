class Solution {
private:

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& count) {

        int row = grid.size();
        int col = grid[0].size();

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                // UP
                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                }

                // DOWN
                if (r + 1 < row && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push({r + 1, c});
                }

                // LEFT
                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                }

                // RIGHT
                if (c + 1 < col && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                }
            }

            // Only increase time if there are more oranges to process
            if (!q.empty()) {
                count++;
            }
        }
    }

public:

    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        int count = 0;

        // Put all initially rotten oranges into queue
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        bfs(grid, q, count);

        // If any fresh orange remains
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return count;
    }
};