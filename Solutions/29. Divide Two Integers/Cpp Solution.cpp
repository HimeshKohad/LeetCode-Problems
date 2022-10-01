class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        
        long long quotient = dividend / divisor;
        if (divisor == -1){
            if (dividend == -2147483648) {  // Control INT Overflow
                dividend += 1;
            }
            return -1*dividend;
        }
        else 
            return quotient;
    }
};
