class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int& current, int& color){
        if (row < 0 || row == image.size() || col < 0 || col == image[0].size() || image[row][col] != current || image[row][col] == color) return;

        image[row][col] = color;

        dfs(row + 1, col, image, current, color);
        dfs(row - 1, col, image, current, color);
        dfs(row, col + 1, image, current, color);
        dfs(row, col - 1, image, current, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int current = image[sr][sc];

        dfs(sr, sc, image, current, color);

        return image;
    }
};