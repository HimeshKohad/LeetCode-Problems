class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Find total area of 2 rectangles
        int area1 = (ax1 - ax2) * (ay1 - ay2);
        int area2 = (bx1 - bx2) * (by1 - by2);
        
        //Find the common area between two rectangles
        int commonArea = 0;
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        
        if(left < right && top > bottom)
            commonArea = (right - left) * (top - bottom);
        
        return area1 + area2 - commonArea;
    }
};
