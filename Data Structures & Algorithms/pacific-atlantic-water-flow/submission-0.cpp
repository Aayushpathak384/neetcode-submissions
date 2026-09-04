class Solution {
private:
    int row, col;

    bool dfs(vector<vector<int>>& heights,
             int i, int j,
             int ocean,
             vector<vector<bool>>& visited) {

        // Pacific: top or left
        if (ocean == 0 && (i == 0 || j == 0))
            return true;

        // Atlantic: bottom or right
        if (ocean == 1 && (i == row - 1 || j == col - 1))
            return true;

        visited[i][j] = true;

        // UP
        if (i > 0 &&
            !visited[i - 1][j] &&
            heights[i - 1][j] <= heights[i][j]) {

            if (dfs(heights, i - 1, j, ocean, visited))
                return true;
        }

        // DOWN
        if (i < row - 1 &&
            !visited[i + 1][j] &&
            heights[i + 1][j] <= heights[i][j]) {

            if (dfs(heights, i + 1, j, ocean, visited))
                return true;
        }

        // LEFT
        if (j > 0 &&
            !visited[i][j - 1] &&
            heights[i][j - 1] <= heights[i][j]) {

            if (dfs(heights, i, j - 1, ocean, visited))
                return true;
        }

        // RIGHT
        if (j < col - 1 &&
            !visited[i][j + 1] &&
            heights[i][j + 1] <= heights[i][j]) {

            if (dfs(heights, i, j + 1, ocean, visited))
                return true;
        }

        return false;
    }

public:
    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        row = heights.size();
        col = heights[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // Check Pacific
                vector<vector<bool>> visited(
                    row, vector<bool>(col, false)
                );

                bool pacific = dfs(
                    heights, i, j, 0, visited
                );

                // Check Atlantic
                visited.assign(
                    row, vector<bool>(col, false)
                );

                bool atlantic = dfs(
                    heights, i, j, 1, visited
                );

                if (pacific && atlantic)
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};