class Solution {
    public int minOperations(List<Integer> nums, int k) {
        int len = nums.size();
        
        HashSet<Integer> hs = new HashSet<>();
        
        for(int i = 1; i <= k; i++) {
            hs.add(i);
        }
        
        int cnt = 0;
        
        for(int i = len - 1; i >= 0; i--) {
            int val = nums.get(i);
            if(hs.contains(val)){
                hs.remove(val);
            }
            
            cnt++;
            
            if(hs.size() == 0) break;
        }
        
        return cnt;
    }
}
