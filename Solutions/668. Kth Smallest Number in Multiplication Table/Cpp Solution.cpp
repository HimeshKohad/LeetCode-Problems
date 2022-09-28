class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int s = 1, e = m * n;
        int ans = 0;
        
        while (s <= e){
            int mid = s + (e - s)/2;
            int count = 0;
            
            for (int i = 1; i <= n; i++){
                count += min (mid/i, m);
            }
            
            if (count >= k){
                ans = mid;
                e = mid - 1;
            }
            
            else {
                s = mid + 1;
            }
        }
        
        return ans;
        
    }
};
