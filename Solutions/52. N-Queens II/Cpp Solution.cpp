#define pb push_back
#define pop pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i > (b); --i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef unordered_set<int> usi;

class Solution {
public:
    int solve(int col, vs &board, vvs &ans, vi &leftRow, vi &upperDiag, vi &lowerDiag, int n) {
        // Initialize a counter to keep track of solutions
        int cnt = 0;

        // base case --> all columns checked --> 0 to n - 1
        if (col == n) {
            return 1;
        }

        // try every row
        for (int row = 0; row < n; row++) {
            // check all three directions --> leftRow, upperDiag, lowerDiag
            if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
                // if safe --> place the Queen
                board[row][col] = 'Q';
                // mark all hash arrays as 1
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                // recursive call
                cnt += solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);

                // backtracking --> remove the Queen
                board[row][col] = '.';
                // mark all hashes as 0
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }

        return cnt;
    }

    int totalNQueens(int n) {
        vvs ans;
        vs board(n, string(n, '.'));

        // creating a hash array for leftRow, upperDiag, lowerDiag
        vi leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);

        // call the solve function and return the count of solutions
        return solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);
    }
};
