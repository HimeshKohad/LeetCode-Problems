class Solution {
public:
    void recursive(TreeNode* root, int level, vector <int> &ans) {
        if (root == NULL) return ;

        if (level == ans.size()) {
            ans.push_back(root -> val);
        }

        recursive(root -> right, level + 1, ans);
        recursive(root -> left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        recursive(root, 0, ans);
        return ans;
    }
};
