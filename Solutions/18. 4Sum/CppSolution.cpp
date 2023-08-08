class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // using 2 pointers (i, j)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                /* target_2 is the remaining element to look for in right array 
                   using left and right pointers */
                long long int target_2 = target - static_cast<long long int>(nums[i]) - nums[j];

                // left pointer just next to j
                int left = j + 1;
                // right pointer at the last element
                int right = n - 1;

                while (left < right) {
                    long long int two_sum = static_cast<long long int>(nums[left]) + nums[right];

                    // binary search in remaining right array
                    if(two_sum < target_2) left++;
                    else if(two_sum > target_2) right--;
                    else{
                        vector<int> quad(4, 0);

                        // store all the 4 elements that add upto target
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];

                        // push this unique quadruplets into res
                        res.push_back(quad);

                        //processing the duplicates
                        while(left < right && nums[left] == quad[2]) ++left;
                        while(left < right && nums[right] == quad[3]) --right;
                    }  
                }
                /* processing the duplicates
                   edge case -> check nums[j + 1] -> because for loop also increments j */
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }

            /* processing the duplicates
               edge case -> check nums[i + 1] -> because for loop also increments i */
            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }

        // return all the unique quadruplets
        return res;
    }
};
