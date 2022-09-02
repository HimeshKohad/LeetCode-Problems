class Solution {
public:
    int arrangeCoins(int n) {
        long s = 0, e = n, mid, tmp;
        
        while (s <= e) {
            mid = s + (e - s) / 2;
            tmp = mid * (mid + 1) / 2;
            
            if (tmp == n){
                return mid;
            } 
            
            if (tmp <= n) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        
        return s - 1;
    }
};
