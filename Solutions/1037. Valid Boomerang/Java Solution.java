class Solution {
    public boolean isBoomerang(int[][] points) {
        
        int a = Math.abs(((points[0][0] - points[1][0])*(points[1][1] - points[2][1])) - ((points[1][0] - points[2][0])*(points[0][1] - points[1][1])));
        
        if (a == 0) return false;
        else return true;
    }
}
