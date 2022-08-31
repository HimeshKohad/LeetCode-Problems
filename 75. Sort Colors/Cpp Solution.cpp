class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Using bubble sort
        int n = nums.size() - 1;
        
        bool swapped = false;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - i; j++){
                if (nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false){
                break;
            }
        }
        
    }
};
