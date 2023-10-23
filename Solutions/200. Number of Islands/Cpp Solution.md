# Solution 1:

```cpp
class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;    //starting point
        queue<pair<int, int>> q;

        q.push({row, col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in the neighbours and mark them in vis
            for(int deltarow = -1; deltarow <= 1; deltarow++){
                for(int deltacol = -1; deltacol <= 1; deltacol++){
                    int nrow = row + deltarow;     //neighbour_row
                    int ncol = col + deltacol;     //neighbour_col

                    //check for out of bound cases 
                    if((abs(deltarow - deltacol) == 1) && (nrow >= 0) && (nrow < n) && (ncol >= 0) && 
                    (ncol < m) && (grid[nrow][ncol] == '1') && (vis[nrow][ncol] == 0)){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return cnt;
    }
};
```

# Solution 2:

```cpp
class Solution {
private:
    void removeIslands(vector<vector<char>>& grid, int i, int j) {
        
        int m = grid.size(), n = grid[0].size();
        
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        removeIslands(grid, i - 1, j);
        removeIslands(grid, i + 1, j);
        removeIslands(grid, i, j - 1);
        removeIslands(grid, i, j + 1);
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    removeIslands(grid, i, j);
                }
            }
        }
        return islands;
        
    }
};
```
