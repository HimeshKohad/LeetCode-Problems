class Solution {
private :

void helper(int i , vector<int> &subSet , vector<int> &nums , vector<vector<int>> &ans)
{
    // Base case
    if(i == nums.size() )
    {
        ans.push_back(subSet) ;
        return ;
    }

    // We pick i-th Element
    subSet.push_back(nums[i]) ;

    // We ask recursion to do rest of the task
    helper(i + 1 , subSet , nums , ans) ;

    // Backtrack and Undo the change we have done
    subSet.pop_back() ;

    // We don't pick the i-th element
    helper(i + 1 , subSet , nums , ans) ;

    return ;
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans ;
    vector<int> subSet ;

    helper(0 , subSet , nums , ans) ;

    return ans ;
}
};
