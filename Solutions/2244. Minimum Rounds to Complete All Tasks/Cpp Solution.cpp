class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map <int, int> mp;

        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }

        int ans = 0;

        for (auto freq : mp) {
            if (freq.second == 1) {
                return -1;
            }a

            if (freq.second % 3 == 0) {
                ans += freq.second / 3;
            }

            else {
                ans += (freq.second / 3) + 1;
            }
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
