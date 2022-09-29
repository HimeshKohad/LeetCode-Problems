class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        if(A == null || A.length == 0)
            return 0;
        
        Map<Integer,Long> map = new HashMap<>();
        
        Arrays.sort(A);
        
        for(int i = 0; i < A.length; i++){
            long count = 1;
            
            for(int j = 0; j < i; j++){
                if(A[i] % A[j] == 0 && map.containsKey(A[i] / A[j])){
                    count += map.get(A[i] / A[j]) * map.get(A[j]);
                }
            }
            
            map.put(A[i],count);
        }
        long sum = 0;
        
        for(long cnt : map.values())
            sum += cnt;
        
        return (int) (sum % (Math.pow(10, 9) + 7));
    }
}
