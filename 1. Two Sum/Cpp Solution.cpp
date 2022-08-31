class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int s = 0; s < n - 1; s++){
            for (int e = s + 1; e < n; e++){
                if (target - nums[s] == nums[e])
                    return {s, e};   
            }
        } 
        return {0};
    }
};
