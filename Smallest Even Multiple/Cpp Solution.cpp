class Solution {
public:
    int smallestEvenMultiple(int n) {
        
        int ans = (n % 2 == 0 && n) ? n : n * 2;
        
        return ans;
    }
};
