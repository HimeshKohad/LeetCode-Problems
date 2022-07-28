class Solution {
    public int maxArea(int[] height) {
        int area = 0;
        int left = 0;
        int right = height.length - 1;
        
        while (left < right){
            int width = right - left;
            int minHeight = Math.min(height[left], height[right]);
            area = Math.max(area, width * minHeight);
            
            if (height[left] > height[right]){
                right--;
            }
            else 
                left++;
        }
        return area;
    }
}
