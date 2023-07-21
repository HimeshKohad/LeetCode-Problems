class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // if root neither has a left path nor a right path -> root is the only element
        // check if root -> val == targetSum
        if (!root -> left && !root -> right) {
            return targetSum == root -> val;
        }

        // traverse left of the tree using a recursive call
        // also keep subtracting the val of prev node each time you traverse a node
        // so that you can check if leaf node is equal to the remaining path sum
        bool leftPath = hasPathSum(root -> left, targetSum - root-> val);

        // similarly traverse for the right path of the tree
        bool rightPath = hasPathSum(root -> right, targetSum - root -> val);

        // return true if any of the two path calls equates to targetSum
        return leftPath || rightPath;
    }
};
