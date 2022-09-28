class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        map <int, int> count;  
        
        for (int i : nums){
            if (i % 2 == 0) count[i]++;
        }
        
        int ans = -1, freq = INT_MIN;  
        
        for (auto i : count){
            if (i.second > freq)
                ans = i.first, freq = i.second;
        }
        
        return ans;
    }
};
