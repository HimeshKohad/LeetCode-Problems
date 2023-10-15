class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1, maxi = INT_MIN;

        for(int i= 0; i < nums.size(); i++) {
            prod *= nums[i];

            if(prod > maxi) {
                maxi = prod;
            }

            if(prod == 0) {
                prod = 1;
            }
        }

        prod = 1;
        for(int i = nums.size() - 1; i > 0; i--) {
            prod *= nums[i];

            if(prod > maxi) {
                maxi = prod;
            }

            if(prod == 0) {
                prod = 1;
            }
        }

        return maxi;
    }
};
