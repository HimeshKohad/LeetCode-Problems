class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0; 

        for (int i = 0; i < nums.length; i++){
            int j = i;
            while (j < nums.length && nums[i] == nums[j]){
                j++;
            }
            nums[k++] = nums[i];
            i = j - 1;
        }
        
        return k;
    }
}
