class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int s = matrix[0][0], e = matrix[n-1][n-1] + 1;
        int mid, count, tmp;
        
        while (s < e) {
            mid = s + (e - s) / 2;
            tmp = n - 1;
            count = 0;

            for (int i = 0; i < n; i++) {
                while (tmp >= 0 && matrix[i][tmp] > mid) tmp--;
                count += tmp + 1;
            }
            
            if (count < k) s = mid + 1;
            else e = mid;
        }
        
        return s;
    }
};
