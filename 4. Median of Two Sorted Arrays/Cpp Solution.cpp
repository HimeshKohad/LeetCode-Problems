class Solution {
private:
    float median(vector<int>& nums1, vector<int>& nums2, int m, int n){
        
        if(m > n) return median(nums2, nums1, n, m);
        
        int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
        
        while(low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;
        
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
        
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 != 0) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            
            else if (l1 > r2) high = cut1 - 1;
            
            else low = cut1 + 1;
        }
    return 0.0;
        
    }
    
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = sizeof(nums1) / sizeof(nums1[0]), n = sizeof(nums2) / sizeof(nums2[0]);
        
        return median(nums1, nums2, m, n);
        
    }
};
