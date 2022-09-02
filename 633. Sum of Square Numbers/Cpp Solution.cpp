class Solution {
public:
    bool judgeSquareSum(int c) {
      
        // Defining a Search Space
        long long int a = 0, b = sqrt(c);
        
        // If a becomes greater than search space --> Stop the search
        while (a <= b){
            
            if (a*a + b*b == c) return true;
            
            else if (a*a + b*b < c) a++;
            
            else b--;
        }
        
        return false;
    }
};
