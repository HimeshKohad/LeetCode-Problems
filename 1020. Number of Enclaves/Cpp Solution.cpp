class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // get the 1's at the boundary and mark them as visited
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // BFS to get the 1's connected to boundary 1's
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // check 4-directional neighbours
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // if connected to boundary 1's and not visited then push in queue and mark as visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int cnt = 0;
        // check remaining 1's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
