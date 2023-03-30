class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        vector <int> map (256, -1);
        int l = 0, r = 0, len = 0;
        int n = s.size();

        while (r < n) {
            if (map[s[r]] != -1) {
                l = max(map[s[r]] + 1, l);
            }

            map[s[r]] = r;

            len = max(len, r - l + 1);
            r++;
        }
        
        return len;
    }
};
