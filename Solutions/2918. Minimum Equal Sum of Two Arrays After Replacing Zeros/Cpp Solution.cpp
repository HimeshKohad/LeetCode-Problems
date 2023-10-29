class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int L1 = nums1.size();
        int L2 = nums2.size();

        long long sum1 = 0;
        long long sum2 = 0;

        int zero1 = 0;
        int zero2 = 0;

        for (int i = 0; i < L1; ++i) {
            sum1 += nums1[i];
            if (nums1[i] == 0) {
                zero1++;
                sum1 += 1;
            }
        }

        for (int i = 0; i < L2; ++i) {
            sum2 += nums2[i];
            if (nums2[i] == 0) {
                zero2++;
                sum2 += 1;
            }
        }

        if (sum1 == sum2) {
            return sum1;
        } 
        
        else if (sum1 < sum2) {
            if (zero1 > 0) {
                return sum2;
            } 
            else {
                return -1;
            }
        } 
        
        else {
            if (zero2 > 0) {
                return sum1;
            } 
            else {
                return -1;
            }
        }
    }
};
