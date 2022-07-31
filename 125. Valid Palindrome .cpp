class Solution {
private: 
    bool valid(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1; // Valid -> True
        }
        
        return 0; // Invalid -> False
    }
    
    char toLowerCase(char ch){
        if ((ch >= 'a' && ch <= 'z')  || (ch >= '0' && ch <= '9')){
            return ch; // Already in lowerCase
        }
        else{
            char temp = ch - 'A' + 'a';
        return temp;
        }
            
    }
    
    bool checkPalindrome (string a) {
        int s = 0, e = a.length() - 1;
        
        while (s <= e){
            if (a[s] != a[e]){
                return 0;
            }
            else {
                s++;
                e--;
            }     
        }
        return 1;
    }

    
public:
    bool isPalindrome(string s) {
        
        // Remove Invalid Characters
        string temp = "";
        
        for (int j = 0; j < s.length(); j++){
            if (valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        
        // Convert ot lowerCase
        for (int j = 0; j < temp.length(); j++){
            temp[j] = toLowerCase(temp[j]);
        }
        
        // Check Palindrome
        return checkPalindrome(temp);
    }
};
