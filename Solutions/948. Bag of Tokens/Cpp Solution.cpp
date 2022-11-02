class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        
        sort(tokens.begin(), tokens.end());
        
        int s = 0, e = n - 1;
        int points = 0, ans = 0;
        
        while (s <= e && (power >= tokens[s] || points > 0)) {
            while (s <= e && power >= tokens[s]) {
                power -= tokens[s++];
                points++;
            }
            
            ans = max(ans, points);
            if (s <= e && points > 0) {
                power += tokens[e--];
                points--;
            }
        }
        
        return ans;
    }
};
