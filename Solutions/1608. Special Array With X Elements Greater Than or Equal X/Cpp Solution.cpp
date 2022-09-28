class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for (int i = 0; i <= n; i++){
            int temp = n;
            int s = 0, e = n - 1;
            
            while (s <= e){
                int mid = s + (e -s)/2;
                
                if (nums[mid] >= i){
                    temp = mid;
                    e = mid - 1;
                }
                else s = mid + 1;
            }
            //cout << temp;
            if ((n - temp) == i) return i;
        }
        
        return -1;
    
    }
};
