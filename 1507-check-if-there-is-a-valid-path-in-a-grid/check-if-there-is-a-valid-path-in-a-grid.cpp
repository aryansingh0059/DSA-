class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // directions: up, down, left, right
        vector<vector<vector<int>>> dirs = {
            {}, // dummy for index 0
            {{0,-1}, {0,1}},       // type 1
            {{-1,0}, {1,0}},       // type 2
            {{0,-1}, {1,0}},       // type 3
            {{0,1}, {1,0}},        // type 4
            {{0,-1}, {-1,0}},      // type 5
            {{0,1}, {-1,0}}        // type 6
        };

        // check if neighbor connects back
        auto isConnected = [&](int nx, int ny, int x, int y) {
            for (auto &d : dirs[grid[nx][ny]]) {
                if (nx + d[0] == x && ny + d[1] == y)
                    return true;
            }
            return false;
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (x == m-1 && y == n-1)
                return true;

            for (auto &d : dirs[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
                    if (isConnected(nx, ny, x, y)) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }
};