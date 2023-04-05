class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long ans = 0, prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            ans = max(ans, (prefixSum + i) / (i + 1));
        }

        return ans;
    }
};
