class Solution {
public:
    string reverseWords(string s) {
        string res;
        int lastSpaceIdx = -1;
        
        for (int strIdx = 0; strIdx < s.length(); strIdx++){
             if ((strIdx == s.length() - 1) || s[strIdx] == ' ') { 
                int reverseStrIdx = (strIdx == s.length() - 1) ? strIdx : strIdx - 1;
                
                for (; reverseStrIdx > lastSpaceIdx; reverseStrIdx--){
                    res += s[reverseStrIdx];
                }
                
                if(strIdx != s.length() - 1){
                    res += ' ';
                }
                
                lastSpaceIdx = strIdx;
            }
        }
        
        return res;
    }
};
