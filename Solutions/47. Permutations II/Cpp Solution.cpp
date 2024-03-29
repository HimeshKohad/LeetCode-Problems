class Solution {
private :

void helper(int pos , int n , vector<int> &nums , vector<vector<int>> &ans)
{
    // Base Case executes when we have traversed the entire nums[]
    if(pos >= n)
    {
        ans.push_back(nums) ;
        return ;
    }

    // Unordered_set ensures we are not taking duplicates and thus not making Duplicate Permutation
    unordered_set<int> set ;

    // The rest logic remains exactly the same
    for(int i = pos ; i < n ; i++)
    {
        // If we have encountered the element before, we will simply skip the rest of iterations
        if(set.find(nums[i]) != set.end() )
        continue ;

        // We insert nums[i] so that we don't create Duplicate Permutations
        set.insert(nums[i]) ;

        // We simply use our swapping logic to create Permutations
        swap(nums[pos] , nums[i]) ;

        // Ask recursion to do rest of the task
        helper(pos + 1 , n , nums , ans) ;

        // Backtrack and undo the change we have done
        swap(nums[pos] , nums[i]) ;
    }

    return ;
}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

    vector<vector<int>> ans ;

    helper(0 , nums.size() , nums , ans) ;

    return ans ;

}
};
