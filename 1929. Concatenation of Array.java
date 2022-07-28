class Solution {
    public int[] getConcatenation(int[] num) {
        int n = num.length;
        int [] concat = new int[n*2];
        for (int i = 0; i<n; i++){
            concat[i] = num[i];
            concat[i+n] = num[i];
        }
        return concat;
    }
}
