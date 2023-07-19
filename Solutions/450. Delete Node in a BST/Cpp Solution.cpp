class Solution {
public:

    TreeNode* findLastRight(TreeNode* root) {
        if (root -> right == nullptr) {
            return root;
        }

        return findLastRight(root -> right);
    }

    TreeNode* helper(TreeNode* root) {
        if (root -> left == nullptr) {
            return root -> right;
        }

        else if (root -> right == nullptr) {
            return root -> left;
        }

        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLastRight(root -> left);
        lastRight -> right = rightChild;

        return root -> left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root -> val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;
        while (root != nullptr) {
            if (root -> val > key) {
                if (root -> left != nullptr && root -> left -> val == key) {
                    root -> left = helper(root -> left);
                    break;
                }

                else {
                    root = root -> left;
                }
            }

            else {
                if (root -> right != nullptr && root -> right -> val == key) {
                    root -> right = helper(root -> right);
                    break;
                }

                else {
                    root = root -> right;
                }
            }
        }

        return dummy;
    }
};
