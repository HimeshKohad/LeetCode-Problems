class Solution {
public:
    /**
     * Solves the Sudoku puzzle recursively using backtracking.
     *
     * @param board the Sudoku board to be solved
     *
     * @return true if the Sudoku puzzle is solved, false otherwise
     *
     * @throws None
     */
    bool solve(vector<vector<char>>& board) {
        // traverse in the matrix
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                // empty slot in the board
                if(board[i][j] == '.') {
                    // try char 1-9 
                    for(char c = '1'; c <= '9'; c++) {

                        // check if the char is safe to place
                        if(isSafe(board, i, j, c)) {
                            // place the char
                            board[i][j] = c;

                            // value place successfully --> return
                            if(solve(board) == true) {
                                return true;
                            }

                            // not able to place any value --> backtrack
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }

                    // if the char is not safe to place --> return false
                    return false;
                }
            }
        }
        // all the slots are filled --> return true
        return true;
    }

    /**
     * Check if it is safe to place a character in the Sudoku board at the given row and column.
     *
     * @param board the Sudoku board
     * @param row the row index
     * @param col the column index
     * @param c the character to be placed
     *
     * @return true if it is safe to place the character, false otherwise
     */
    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            // check if col already has the char c
            if(board[i][col] == c) {
                return false;
            }

            // check if row already has the char c
            if(board[row][i] == c) {
                return false;
            }

            // checking the 3x3 submatrix
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }

        // the character is safe to place
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
