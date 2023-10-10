class Solution {
    public int minOperations(int[] nums) {
        int len = nums.length;
        HashMap<Integer, Integer> h = new HashMap<>();
        
        for(int i = 0; i < len; i++) {
            int val = nums[i];
            if(h.get(val) == null) {
                h.put(val, 1);
            }
            else {
                int m = h.get(val);
                m++;
                h.put(val, m);
            }
        }
        
        List<Integer> li = new ArrayList<>();
        for(Map.Entry<Integer, Integer> entry : h.entrySet()) {
            li.add(entry.getValue());
        }
        
        int ans = 0;
        
        for(int i = 0; i < li.size(); i++) {
            int cn = li.get(i);
            if(cn == 1){
                ans=-1;
                break;
            }
            else {
                while(cn > 0) {
                    if(cn%3 == 0) {
                        int div = cn / 3;
                        ans += div;
                        cn = 0;
                    }
                    else {
                        cn -= 2;
                        ans++;
                    }
                }
                
                if(cn < 0) {
                    ans = -1;
                    break;
                }
            }
        }
        
        return ans;
    }
}
