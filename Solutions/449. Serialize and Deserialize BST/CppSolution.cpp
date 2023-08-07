/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr) s.append("#,");
            
            else s.append(to_string(curr -> val) + ',');

            if(curr != nullptr) {
                q.push(curr -> left);
                q.push(curr -> right);
            }
        }

        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');

            if(str == "#") node -> left = nullptr;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node -> left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if(str == "#") node -> right = nullptr;
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node -> right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
