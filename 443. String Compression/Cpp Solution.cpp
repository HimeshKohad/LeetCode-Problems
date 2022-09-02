class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIdx = 0;
        int n = chars.size();
        
        while (i < n){
            int j = i + 1;
            while (j < n && chars[i] == chars[j]){
                j++;
            }
            
            chars[ansIdx++] = chars[i];
            
            int cnt = j - i;
            if (cnt > 1){
                string count = to_string(cnt);
                for (char ch : count){
                    chars[ansIdx++] = ch;
                }
            }
            i = j;
        }
        
        return ansIdx;
    }
};
