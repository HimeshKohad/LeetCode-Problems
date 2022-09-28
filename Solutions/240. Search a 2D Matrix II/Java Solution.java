class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {

            if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
                return false;
            }

            int row = matrix.length;
            int col = matrix[0].length;

            int i = 0;
            int j = col - 1;

            while (i < row && j >= 0) {
                
                int val = matrix[i][j];

                if (val == target) {
                    return true;
                }
                else if (target < val) {
                    j--; 
                }
                else {
                    i++; 
                }
            }

        return false;
        
    }
}
