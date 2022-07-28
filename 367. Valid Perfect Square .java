class Solution {
    public boolean isPowerOfFour(int n) {
        if (n <= 0){
            return false;
        }
        while (n  >3){
            if (n % 4 != 0){
                return false;
            }
            n /= 4;
        }
        return n == 1;
    }
}
