class Solution {
    public int divide(int dividend, int divisor) {
        int quotient = dividend / divisor;
        if (divisor == -1){
            if (dividend == -2147483648 ){
                dividend += 1;
            }
            return -1*dividend;
        }
        else 
            return quotient;
    }
}
