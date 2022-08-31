class Solution {
    
    private int n;
    private int m;
    
    private void removeIslands(char[][] grid, int i, int j) {
        
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
        
        grid[i][j] = '0';
        
        removeIslands(grid, i + 1, j);
        removeIslands(grid, i - 1, j);
        removeIslands(grid, i, j + 1);
        removeIslands(grid, i, j - 1);
        
    }
    
    
    public int numIslands(char[][] grid) {
        
        int count = 0;
        n = grid.length;
        m = grid[0].length;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    removeIslands(grid, i, j);
                    ++count;
                }
        }    
        
        return count;
        
    }
}
