class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector <int> nums;
        
        ListNode* curr = head;
        
        while (curr != NULL){
            nums.push_back(curr -> val);
            curr = curr -> next;
        }
        
        for (int i = 0; i < nums.size() / 2; i++){
             if(nums[i] != nums[nums.size() - i - 1]) return false;
        }
        
        return true;
        
    }
};
