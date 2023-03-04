class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long minPos = -1;
        long long maxPos = -1;
        long long probIdx = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                probIdx = i;
            }

            if(nums[i] == minK){
                minPos = i;
            }

            if(nums[i] == maxK){
                maxPos = i;
            }
            
            long long smaller = min(minPos, maxPos);
            long long temp = smaller - probIdx;

            ans += ((temp <= 0) ? 0 : temp); 
        }

        return ans;
    }
};
