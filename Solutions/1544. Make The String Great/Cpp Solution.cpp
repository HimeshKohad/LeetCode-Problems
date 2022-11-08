class Solution {
public:
    string makeGood(string s) {
        
        vector <char> stack;
        
        for (auto curr: s) {
            if (!stack.empty() && abs(stack.back() - curr) == 32) {
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
