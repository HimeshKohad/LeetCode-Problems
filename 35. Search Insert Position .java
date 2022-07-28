class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        

        while (l < r) {
            final int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
            }

        return l;
    }
}
