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
