class Solution {
    
private:
    void helper(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &ans){
        
        // If k = 0 --> We have already generated a valid subset of k length
        if (k == 0){
            ans.push_back(subSet);
            return ;
        }
        
        // If we dont have enough ele to generate our sebset --> don't move further
        if (k > n - i + 1) return ;
        
        // If i > n --> Stop going further
        if (i > n) return ;
        
        // We are using same logic as the Subsets problem
        // Pick the ith ele
        subSet.push_back(i);
        
        // Let recursion do the rest
        helper(i + 1, n, k - 1, subSet, ans);
        
        // Backtrack and undo the change
        subSet.pop_back();
        
        // Don't pick the ith ele
        helper(i + 1, n, k, subSet, ans);
        
    }
    
    
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> subSet;
        
        helper(1, n, k, subSet, ans);
        
        return ans;
        
    }
};
