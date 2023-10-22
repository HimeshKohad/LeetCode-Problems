class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = 1e9;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    if(nums[i] < nums[j] && nums[k] < nums[j]) {
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        
        if(ans == 1e9) return -1;
        return ans;
    }
};
