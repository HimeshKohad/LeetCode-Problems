class Solution {
public:
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return helper(nums, 0, nums.size() - 1);
        
    }
  
    TreeNode* helper(vector<int>& nums, int s,int e){
        
        if(s <= e){
            
            int mid = s + (e - s)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root -> left = helper(nums, s, mid - 1);
            root -> right = helper(nums, mid + 1, e);
            
            return root;
            
        }
        
        return NULL;
    }
};
