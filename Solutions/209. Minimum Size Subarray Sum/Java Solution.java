class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        int sum = 0;
        
        for (int i = 0; i < n; i++){
            if (nums[i] == target)
                return 1;
        }
        
        for (int s = 0, e = 0; e < n; ++e){
            sum += nums[e];
            while (sum >= target){
                ans = Math.min(ans, e - s + 1);
                sum -= nums[s++];
            }
        }
        
        return ans < Integer.MAX_VALUE ? ans : 0;
    }
}
