class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == NULL || head -> next == NULL || k == 0) return head;
        
        ListNode* curr = head;
        
        int size = 1;
        
        while (curr -> next != NULL){
            size++;
            curr = curr -> next;
        }
        
        curr -> next = head;
        
        if (k > size)
            k = k % size;
        
        while (--size >= k) {
            curr = curr -> next;
        }
        
        ListNode* newHead = curr -> next;
        curr -> next = NULL;
        
        return newHead;
    }
};
