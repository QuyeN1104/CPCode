class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Đếm thành phần liên thông trong đồ thị 
        int rows = grid.size(); int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        queue<pair<int,int>> q;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != '1' || visited[i][j]) continue;
                ++ans;
                visited[i][j] = true;         // mark when pushing
                q.push({i, j});
                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                        if (grid[nr][nc] != '1' || visited[nr][nc]) continue;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
}
};