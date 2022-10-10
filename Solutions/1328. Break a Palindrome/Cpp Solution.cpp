class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.length();
        
        if (n == 1) return "";
        
        for (int i = 0; i < n/2; i++){
            if (palindrome[i] > 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[n - 1] = 'b';
        
        return palindrome;
    }
};

________________________________________________________________________________________
Here n == 1 --> return "";
and we want palindrome string to be lexicographical --> return the 1st non 'a' by 'a'
Edge case: "aa" --> here change the 2nd 'a' to 'b' to break the palindrome
