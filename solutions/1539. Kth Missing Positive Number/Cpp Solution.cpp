class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int s = 0, e = arr.size();
        
        while (s < e){
            int mid = s + (e - s)/2;
            
            if (k < arr[0])
                return k;
            
            if (arr[mid] - mid - 1 < k)
                s = mid + 1;
            
            else 
                e = mid;
        }
        
        return s + k;
        
    }
};
