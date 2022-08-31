class Solution {
private :

void help(int i, vector<int> &arr, int B, int currSum, vector<int> &subSet, vector<vector<int>> &ans) {

    // If our currSum is equal to B(Target), we have reached a Valid Combination
    if(currSum == B)
    {
        ans.push_back(subSet);
        return;
    }

    // If our currSum exceeds B(Target), there's no point in proceeding further --> STOP
    if(currSum> B) return;

    // If we have reached the end of arr[], we cannot go further as we don't have anymore elements --> STOP
    if(i >= arr.size()) return;

    // We skip the i-th element
    help(i + 1, arr, B, currSum, subSet, ans);

    // We include the i-th into our currSum
    currSum += arr[i];

    // We push the i-th Element into our subSet
    subSet.push_back(arr[i]);

    // We keep on the i-th Element & ask recursion to do rest of the task
    help(i, arr, B, currSum, subSet, ans);

    // When we come back, we need to backtrack & undo the change
    currSum -= arr[i];

    subSet.pop_back();
}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<int> subSet;

    int currSum = 0;

    vector<vector<int>> ans;

    // This sorting ensures all the elements in each Subset are also in sorted order
    sort(candidates.begin(), candidates.end());

    help(0, candidates, target, currSum, subSet, ans);

    return ans;
}
};
