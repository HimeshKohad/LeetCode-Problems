Approach 1: Iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // if the list is NULL or has only one element
        if (head == NULL || head -> next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while (curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
};

n --> number of nodes
Time Complexity: O(n)
Space Complexity: O(1)
_______________________________________________________________________________________
Approach 2: Recursive

class Solution {
public:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
        if (curr == NULL){
            head = prev;
            return;
        }
        ListNode* forward = curr -> next;
        reverse(head, forward, curr);
        curr -> next = prev;
    }
        
        
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head, curr, prev);
        return head;
    }
};
