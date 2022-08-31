class Solution {
    public int firstMissingPositive(int[] nums) {
        boolean one = false;
        int n = nums.length;
        
        for (int i = 0; i < n; i++){
            if (nums[i] == 1) one = true;
            
            if (nums[i] < 1 || nums[i] > n){
                nums[i] = 1;
            }
            
        }
        if (one == false) return 1;
        
        for (int i = 0; i < n; i++){
            int index = Math.abs(nums[i]);
            nums[index - 1] = -Math.abs(nums[index - 1]);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
}
