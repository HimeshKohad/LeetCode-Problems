class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(32, 0);
        
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1 << bit)) {
                    count[bit]++;
                }
            }
        }
        
        int res = 0;
        for (int bit = 31; bit >= 0; bit--) {
            if (count[bit] >= k) {
                res |= (1 << bit);
            }
        }
        
        return res;
    }
};
