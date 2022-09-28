class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, count;
        
        while (s <= e){
            int mid = s + (e - s)/2;
            count = 0;
            
            for (int n : nums){
                if (n <= mid) count++;
            }
            
            if (count <= mid) s = mid + 1;
            
            else e = mid - 1;
        }
        
        return s;
    }
};
