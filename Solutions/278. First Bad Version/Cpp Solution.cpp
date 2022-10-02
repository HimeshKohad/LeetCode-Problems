class Solution {
public:
    int firstBadVersion(int n) {
        
        int s = 0, e = n, ans;
        
        while (s <= e){
            int mid = s + (e - s)/2;
            
            if(isBadVersion(mid)){
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        
        return ans;
    }
};
