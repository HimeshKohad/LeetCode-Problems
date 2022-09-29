class Solution {
    public int search(int[] nums, int target) {
        
        int s = 0, e = nums.length - 1;
        
        while (s <= e){
            int mid = s + (e - s)/2;
            
            if (nums[mid] < target){
                s = mid + 1;
            }
            
            else if (nums[mid] == target){
                return mid;
            }
            
            else
                e = mid - 1;
            
            mid = s + (e - s)/2;
        }
        return -1;
        
    }
}
