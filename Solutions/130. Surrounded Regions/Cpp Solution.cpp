class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = board.size(), m = board[0].size();

        // check all 4-directional neighbours
        for(int i = 0; i < 4; i++) {
            // get new row and column
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // get 4-directional neighbours
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int j = 0; j < m; j++) {
            // first row
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delrow, delcol);
            }
            // last row
            if(!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }

        for(int i = 0; i < n; i++) {
            // first column
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            // last column
            if(!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }

        // get remaining O's and mark them as X's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
