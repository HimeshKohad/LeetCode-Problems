class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(!root) return nullptr;

        if(root == p || root == q) return root;

        // recursive traversal
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        // if both are !NULL -> this node is the lca
        if(left != nullptr && right != nullptr) return root;

        // if right is NULL return left node
        else if(right == nullptr && left != nullptr) return left;

        // if left is NULL return right node
        else if(left == nullptr && right != nullptr) return right;

        // if both are NULL return root
        else return nullptr;
    }
};
