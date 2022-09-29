class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
   
        int s = 0, e = arr.size() - k;
        
        while (s < e) {
            int mid = (s + e) / 2;
            
            if (x - arr[mid] > arr[mid + k] - x) s = mid + 1;
            
            else e = mid;
        }
        
        return vector<int>(arr.begin() + s, arr.begin() + s + k);
    }
};
