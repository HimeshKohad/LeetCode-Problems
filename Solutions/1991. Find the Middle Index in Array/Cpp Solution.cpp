class Solution {
public:
    int leftSum(vector<int>& nums, int idx) {
        int sumLeft = 0;
        for(int i = 0; i < idx; i++) {
            sumLeft += nums[i];
        }

        return sumLeft;
    }

    int rightSum(vector<int>& nums, int n, int idx) {
        int sumRight = 0;

        for(int i = n - 1; i > idx; i--) {
            sumRight += nums[i];
        }

        return sumRight;
    }

    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(leftSum(nums, i) == rightSum(nums, n, i)) return i;
        }

        return -1;
    }
};
