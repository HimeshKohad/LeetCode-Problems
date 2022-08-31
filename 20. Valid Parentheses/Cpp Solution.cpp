class Solution {
public:
    bool isValid(string s) {
        stack <char> st;        
        
        for (char c : s) {
            if (st.empty()){
                st.push(c);
            } 
            
            else{
                if (c == '(' || c == '{' || c == '[') {
                    st.push(c);
                } 
                
            else{
                char v = st.top();
                if ((c == ')' && v == '(') || (c == '}' && v == '{') || (c == ']' && v == '[')) {
                        st.pop();
                    }
                else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};
