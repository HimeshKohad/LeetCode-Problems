class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        
        int n = nums.length;
        
        int ans = n;
        
        for (int i = 0; i < n; i++){
            if (nums[i] != i){
                ans = i;
                break;
            }
            
        }
        
        return ans;
    }
}
