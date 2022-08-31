class Solution {
private :

void help(int i, vector<int> &arr, int n, vector<int> &subSet, vector<vector<int>> &powerSet, int sum, int target) {

    // base case
    // If sum is equal to target, we have reached a Valid Combination --> STOP
    if(sum == target)
    {
        powerSet.push_back(subSet) ;
        return;
    }

    // If sum becomes greater than target --> STOP as moving further the sum will only be greater than target 
    // as there are no negative values in the array
    if(sum > target) return ;

    // If we reach the end of arr[], we cannot go any further so we return back
    if(i == n) return;

    // Include the i-th Element into our Subset & Sum
    subSet.push_back(arr[i]) ;
    sum += arr[i] ;

    // Let recursion do rest of the task
    help(i + 1, arr, n, subSet, powerSet, sum, target) ;

    // Backtrack and undo the change we have done
    subSet.pop_back();
    sum -= arr[i];

    // Use the While Loop to skip all the duplicate occurrences of i-th Element
    while(i + 1 < arr.size() && arr[i] == arr[i + 1]) i++ ;

    // Don't pick the i-th Element and ask recursion to do rest of the task
    help(i + 1, arr, n, subSet, powerSet, sum, target) ;
}


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    vector<int> subSet ;
    vector<vector<int>> powerSet ;
    int sum = 0;
    int n = candidates.size() ;
    sort(candidates.begin(), candidates.end()) ;

    help(0, candidates, n, subSet, powerSet, sum, target) ;

    return powerSet ;
}
};
