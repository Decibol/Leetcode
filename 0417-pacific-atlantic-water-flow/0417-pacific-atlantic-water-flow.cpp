class Solution {
public:
    void dfs(int r, int c, int prevHeight, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if (r < 0 || r == heights.size() || c < 0 || c == heights[0].size() || visited[r][c] || heights[r][c] < prevHeight){
            return;
        }

        visited[r][c] = true;

        dfs(r + 1, c, heights[r][c], heights, visited);
        dfs(r - 1, c, heights[r][c], heights, visited);
        dfs(r, c + 1, heights[r][c], heights, visited);
        dfs(r, c - 1, heights[r][c], heights, visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int c = 0; c < cols; ++c){
            dfs(0, c, heights[0][c], heights, pacific);
            dfs(rows - 1, c, heights[rows - 1][c], heights, atlantic);
        }

        for (int r = 0; r < rows; ++r){
            dfs(r, 0, heights[r][0], heights, pacific);
            dfs(r, cols - 1, heights[r][cols - 1], heights, atlantic);
        }

        vector<vector<int>> result;

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (pacific[i][j] && atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};