class Solution {
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int r, int c, int pr, int pc) {
        visited[r][c] = true;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (nr == pr && nc == pc) continue;          // skip parent
            if (grid[nr][nc] != grid[r][c]) continue;   // different char
            if (visited[nr][nc]) return true;            // cycle found!
            if (dfs(grid, visited, nr, nc, r, c)) return true;
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j])
                    if (dfs(grid, visited, i, j, -1, -1))
                        return true;
        return false;
    }
};