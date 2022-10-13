class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size(), cnt = 0;
        
        for (int i = 0; i < n; i++){
            bool flag = false;
            for (int j = 0; j < n - 1; j++){
                if(s[j] == '0' && s[j + 1] == '1'){
					s[j] = '1';
					s[j + 1] = '0';
					flag = true;
					j++;
                }
            }
            if (flag) cnt++;
        }
        
        return cnt;
    }
};
