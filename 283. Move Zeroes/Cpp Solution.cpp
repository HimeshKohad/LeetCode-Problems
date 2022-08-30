class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;    // i indicates the pos for the 1st nonZero value
        int n = nums.size();
        
        // Shifting all nonZero values to the left
        for (int j = 0; j < n; j++){
            
            if (nums[j] != 0){
                swap (nums[j], nums[i]);
                i++;
            }
            
        }
        
    }
};
