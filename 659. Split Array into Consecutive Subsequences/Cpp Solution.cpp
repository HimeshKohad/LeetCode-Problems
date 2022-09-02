class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map <int, int> freq, hypo;
        
        for (int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        
        for(auto i : nums){
            if (freq[i] == 0) continue;
            freq[i]--;
            if (hypo[i - 1] > 0){
                hypo[i - 1]--;
                hypo[i]++;
            }
            
            else if (freq[i + 1] != 0 && freq[i + 2] != 0){
                freq[i + 1]--;
                freq[i + 2]--;
                hypo[i + 2]++;
            }
            else return false;
        }
        
        return true;
    }
};
