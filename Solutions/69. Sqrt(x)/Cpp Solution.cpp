class Solution {
public:
long long int BinarySearch(int n) {

    int s = 0;
    int e = n;
    
    long long int ans = -1;
        while (s<=e) {
            long long int mid = s + (e - s)/2;
            long long int square = mid * mid;  // Avoid int overflow
         
            if (square == n) {
                return mid;
            }
        
            if (square < n) {
                ans = mid;
                s = mid + 1;
            }
    
            else {
                e = mid - 1;
            }
            
            mid = s + (e - s)/2;
        
        }

        return ans;
    }
  
    int mySqrt(int x) {
        return BinarySearch(x);  
    }
};
