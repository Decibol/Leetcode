class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int& current, int& color){
        if (r < 0 || r == image.size() || c < 0 || c == image[0].size() || image[r][c] != current || image[r][c] == color) return;

        image[r][c] = color;

        dfs(r - 1, c, image, current, color);
        dfs(r + 1, c, image, current, color);
        dfs(r, c + 1, image, current, color);
        dfs(r, c - 1, image, current, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int current = image[sr][sc];

        dfs(sr, sc, image, current, color);

        return image;    
    }
};