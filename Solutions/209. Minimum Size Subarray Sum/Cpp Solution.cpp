class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        
        for (int i = 0; i < n; i++){
            if (nums[i] == target)
                return 1;
        }
        
        for (int s = 0, e = 0; e < n; ++e){
            sum += nums[e];
            while (sum >= target){
                ans = min(ans, e - s + 1);
                sum -= nums[s++];
            }
        }
        
        return ans < INT_MAX ? ans : 0;
        
    }
};
