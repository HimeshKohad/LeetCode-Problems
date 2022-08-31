class Solution {
private:

void helper(int pos , int n , vector<int> &nums , vector<vector<int>> &ans)
{
    // If we have reached the end of nums[], we have found a Valid Permutations of nums[]
    if(pos >= n)
    {
        ans.push_back(nums) ;
        return ;
    }

    // Otherwise we iterate over all the other elements and try to generate Permutations by swapping nums[pos] with     nums[i]
    for(int i = pos ; i < n ; i++)
    {
        // We create one Unique Permutation by swapping nums[pos] with nums[i]
        swap(nums[pos] , nums[i]) ;

        // And we ask Recursion to handle rest of the task
        helper(pos + 1 , n , nums , ans) ;

        // But after we come back, we must backtrack and undo the changes we have done
        swap(nums[pos] , nums[i]) ;
    }

    return ;
}

public:
    vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> ans ;

    helper(0 , nums.size() , nums , ans) ;

    return ans ;
}
};
