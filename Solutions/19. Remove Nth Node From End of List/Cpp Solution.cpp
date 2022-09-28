// GeeksForGeeks Reference --> Link: https://www.geeksforgeeks.org/remove-nth-node-from-end-of-the-linked-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // store the length of list
        int len = 0;
        ListNode *tmp = head;
        while (tmp != NULL){
            len++;
            tmp = tmp -> next;
        }
        
        if (n > len) return head; // if n > length then we cant remove node
        
        else if (n == len) return head -> next; // remove head node
        
        else {  // remove length - nth node from the starting == nth node from the end of the list
            int diff = len - n;
            ListNode* prev = NULL;
            ListNode* curr = head;
            for (int i = 0; i < diff; i++){
                prev = curr;
                curr = curr -> next;
            }
            
            prev -> next = curr -> next;
            return head;
        }
        
        
    }
};
