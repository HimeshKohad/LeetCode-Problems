class Solution {
    public int longestValidParentheses(String s) {
        
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int max = 0;
        
        int n = s.length();
        
        for (int i = 0; i < n; i++){
            char c = s.charAt(i);
            
            if (c == '('){
                st.push(i);
            }
            
            else {
                st.pop();
                
                if (st.isEmpty()){
                    st.push(i);
                }
                
                else {
                    int len = i - st.peek();
                    max = Math.max(max, len);
                }
            }
        }
        
        return max;
    }
}
