class Solution {
public:
    string convert(string s, int nRows) {
        
        if(nRows <= 1 || s.length() <= 1) return s;

        string result = "";

        int cycle = 2 * nRows - 2;

        for(int i = 0; i < nRows; ++i)
        {
            for(int j = i; j < s.length(); j += cycle){
               result += s[j];

               int secondJ = (j - i) + cycle - i;

               if(i != 0 && i != nRows-1 && secondJ < s.length())
                   result += s[secondJ];
            }
        }

        return result;
    }
};
