class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1, e = num;
        
        while(s <= e){
            
            long mid = s + (e - s)/2; // Avoid integer overflow
            
            if(mid*mid == num) {
                return true;
            }
            
            else if(mid*mid < num) {
                s = mid + 1;
            }
            
            else e = mid - 1;
        }
        return false;
    }
};
