class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        
        map <int, int> mp;
        for (int i = 0; i < n - 1; i++){
            mp[nums[i] + nums[i + 1]]++;  
        }
        
        for (auto it: mp){
            if (it.second > 1)  
                return true;    
        }
        
        return false;
    }
};
