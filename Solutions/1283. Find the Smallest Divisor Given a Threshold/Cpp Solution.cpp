class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int s = 1, e = 1000000;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            int sum = 0;
            for (int i = 0; i < nums.size(); i++){
                sum += nums[i]/mid;
                
                if (nums[i] % mid > 0){
                    sum++;
                }
            }
            
            if (threshold >= sum) e = mid - 1;
            
            else s = mid + 1;
        }
        
        return s;
    }
};
