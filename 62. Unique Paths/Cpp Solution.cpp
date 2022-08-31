class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1){  // There is only one path in this case either right or down.
            return 1;
        }
        
        m--;
        n--;
            
        if (m < n){       // Swap m and n, to make m the bigger number
            m = m + n;
            n = m - n;
            m = m - n;
        }
        
        long ans = 1;
        int j = 1;
        
        for (int i = m + 1; i <= m + n; i++, j++){
            ans *= i;
            ans /= j;
        }
        
        return (int) ans;
    }
};
