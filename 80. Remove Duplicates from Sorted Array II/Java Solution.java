class Solution {
    public int removeDuplicates(int[] nums) {
        
        int n = nums.length;
        
        if (n < 3) return n;
        
        int idx = 2;
        
        for(int i = 2; i < n; i++){
             if(nums[i] != nums[idx - 2]){
                 nums[idx] = nums[i];
                 idx++;
             }
        }
        
        return idx;
        
    }
}
