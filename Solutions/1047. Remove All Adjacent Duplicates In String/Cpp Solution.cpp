class Solution {
public:
    string removeDuplicates(string s) {
        
        vector <char> stack;
        
        for (auto curr: s) {
            if (!stack.empty() && (stack.back() == curr)) {
                stack.pop_back();
            }
            
            else {
                stack.push_back(curr);
            }
        }
        
        string ans (stack.begin(), stack.end());
        
        return ans;
        
    }
};
