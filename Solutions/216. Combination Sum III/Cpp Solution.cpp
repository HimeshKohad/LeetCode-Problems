class Solution {
    
private:
    void helper(int i, int k, int currSum, int n, vector <int> &subSet, vector<vector<int>> &ans){
        
        // IF currSum > n --> Don't proceed further --> return
        if (currSum > n){
            return ;
        }
        
        // If k = 0, check whether currSum is equal to n or not
        if (k == 0){
            
            // If currSum is equal to n, we include the subset into our ans[]
            if (currSum == n){
                ans.push_back(subSet);
            }
            
            // Else we simply return without including the subset
            return ;
        }
        
        // If i becomes equal to 10 --> don't proceed further --> return
        if (i == 10) return ;
        
        // We include the i-th Number into our currSum & also into our Subset[]
        currSum += i;
        subSet.push_back(i);
        
        // Ask recursion to do the rest of the task
         helper(i + 1, k - 1, currSum, n, subSet, ans);
        
        // Backtrack and undo the changes
        currSum -= i;
        subSet.pop_back();
        
        // We don't include the i-th Number and ask recursion to do the rest of the Combinations
        helper(i + 1, k, currSum, n, subSet, ans);
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector <int> subSet;
        
        vector<vector<int>> ans;
        
        helper(1, k, 0, n, subSet, ans);
        
        return ans;
        
    }
};
