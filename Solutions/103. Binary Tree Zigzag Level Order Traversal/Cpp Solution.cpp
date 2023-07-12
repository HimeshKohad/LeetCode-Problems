class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // same code as a simple level order traversal
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue <TreeNode*> q;
        q.push(root);

        // initialize a counter to determine the level
        int cnt = 1;

        while(!q.empty()) {
            int size = q.size();
            vector <int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node -> left != NULL) q.push(node -> left);
                if (node -> right != NULL) q.push(node -> right);
                level.push_back(node -> val);
            }

            // every alternate level reverse the 'level' vector
            if (cnt % 2 == 0) {
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);

            // increase the cnt after you push the level vector in ans
            cnt++;
        }

        return ans;
    }
};
