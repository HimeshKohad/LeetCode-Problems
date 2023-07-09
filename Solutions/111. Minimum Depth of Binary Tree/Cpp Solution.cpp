class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        if (!root -> left) 
            return minDepth(root -> right) + 1;

        else if (!root -> right)
            return minDepth(root -> left) + 1;

        int lh = minDepth(root -> left);
        int rh = minDepth(root -> right);

        return min(lh, rh) + 1;
    }
};
