class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        for(int i = 0;i < n - 1; i++){
            int s = i + 1;
            int e = n;
            
            while(s < e){
                int mid = s + (e - s)/2;
                
                if(nums[mid] == target - nums[i]) 
                    return {i + 1, mid + 1};
                
                else if(nums[mid] >= target - nums[i]) 
                    e = mid;
                
                else s = mid + 1;
            }
            
            if(s != nums.size() && nums[s] == target - nums[i]) 
                return {i + 1,s + 1};
            
        }
        
        return {0}; 
    }
};
