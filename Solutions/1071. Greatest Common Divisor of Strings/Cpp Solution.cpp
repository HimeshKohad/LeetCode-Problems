class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1 + s2 != s2 + s1){
            return "";
        }
        
        return s1.substr(0, gcd(size(s1), size(s2)));
    }
};
