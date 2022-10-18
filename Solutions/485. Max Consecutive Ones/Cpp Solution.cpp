class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int onesCnt = 0, maxCnt = 0;
        
        for (auto num : nums) {
            if (num == 0) {
                maxCnt = max(maxCnt, onesCnt);
                onesCnt = 0;
            }
            
            else {
                onesCnt++;
            }
        }
        
        return max(maxCnt, onesCnt);
    }
};
