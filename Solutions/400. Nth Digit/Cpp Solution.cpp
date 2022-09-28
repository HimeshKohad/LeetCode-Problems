class Solution {
public:
    int findNthDigit(int n) {
        
        if (n <= 9) return n;
        
        long len = 1;
        long start = 1;
        long count = 9;
            
        while (n > len * count){
            n -= len * count;
                
            len ++;
            start *= 10;
            count *= 10;
        }  
        
        long num = start + (n - 1)/len;
        long idx = (n - 1) % len;
        
        return to_string(num)[idx] - '0';
        
    }
};
