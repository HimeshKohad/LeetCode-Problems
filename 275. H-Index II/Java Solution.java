class Solution {
    public int hIndex(int[] citations) {
        
        int n = citations.length;
        int s = 0, e = n;
        
        while (s < e){
            int mid = s + (e - s)/2;
            
            if (n - mid <= citations[mid])
                e = mid;
            
            else 
                s = mid + 1;
            
        }
        
        return n - e;
        
    }
}
