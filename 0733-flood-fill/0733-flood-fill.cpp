class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int current = image[sr][sc];
        image[sr][sc] = color;
        
        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (auto const& [dr, dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr == image.size() || nc < 0 || nc == image[0].size() || image[nr][nc] == color || image[nr][nc] != current) continue;

                image[nr][nc] = color;

                q.push({nr, nc});                
            }
        }

        return image;
    }
};