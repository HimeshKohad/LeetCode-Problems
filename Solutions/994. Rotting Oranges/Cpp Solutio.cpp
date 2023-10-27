class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // format: {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        // visited array: copy of original grid
        vector<vector<int>> vis(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Use 2 to indicate a rotten orange
                }
                else {
                    vis[i][j] = grid[i][j]; // Use the grid values directly
                }
            }
        }

        int time = 0;
        // 4-directional neighbours
        int dRow[] = {0, 1, 0, -1};
        int dCol[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nrow = r + dRow[i];
                int ncol = c + dCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 1
                    && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // Use 2 to indicate a rotten orange
                }
            }
        }

        // Check and return -1, if fresh oranges are left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
