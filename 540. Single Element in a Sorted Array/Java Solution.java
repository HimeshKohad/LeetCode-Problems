class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int s = 0, e = nums.length - 1;
        
        while (s < e){
            int mid = s + (e - s)/2;
            if (mid % 2 == 1) mid--;
            
            if (nums[mid] != nums[mid + 1]){
                e = mid;
            } 
            
            else s = mid + 2;
        }
        
        return nums[s];
        
    }
}
