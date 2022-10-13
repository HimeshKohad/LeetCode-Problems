class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        int cnt = 0;
        
        while (curr != 0 && cnt < 2){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        if (next != NULL){
            head -> next = swapPairs(next);
        }
        
        return prev;
    }
};
