class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        
        long long int commonArea = 0;
        
        long long int left = max(rect1[0], rect2[0]);
        long long int right = min(rect1[2], rect2[2]);
        long long int top = min(rect1[3], rect2[3]);
        long long int bottom = max(rect1[1], rect2[1]);
        
        if(left < right && top > bottom) {
            commonArea = (right - left) * (top - bottom);
        }
        
        if (commonArea != 0) {
            return true;
        }
        
        return false;
        
    }
};
