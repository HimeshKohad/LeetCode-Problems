## 328. Odd Even Linked List

### Problem Description

Given the ```head``` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in ```O(1)``` extra space complexity and ```O(n)``` time complexity.

Example 1:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/b7bade71-29c9-4fdc-ba93-735836e765ff)

```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

Example 2:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/c979b781-0caf-4494-95ae-3960cbdaebc1)

```
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

**Constraints:**

- The number of nodes in the linked list is in the range ```[0, 104]```.
- ```-106 <= Node.val <= 106```

<hr>

### Approach:

1. The function begins by checking if the head of the linked list is NULL. If it is, it means the list is empty, so the function returns NULL as the result.

2. If the list is not empty, the function proceeds to initialize three pointers: odd, even, and evenHead. The odd pointer is set to the head of the list, while the even pointer is set to the next node after the head. The evenHead pointer is also set to the even pointer, which will be useful later.

3. The while loop is then used to rearrange the nodes in the linked list. The loop continues as long as both even and even->next are not NULL. This means there are still nodes to process.

4. Within the loop, the odd->next pointer is updated to point to the node after the even node, effectively skipping over the even node. The odd pointer is then moved forward to the next node, which becomes the new odd node.

5. Similarly, the even->next pointer is updated to point to the node after the odd node, skipping over the odd node. The even pointer is moved forward to the next node, which becomes the new even node.

6. Steps 4 and 5 are repeated until the end of the linked list is reached or there are no more nodes to process.

7. After the loop, the odd->next pointer is set to evenHead. This is done to connect the last odd node (reached in step 4) to the first even node (which was stored in evenHead).

8. Finally, the function returns the modified linked list with the nodes rearranged in the desired order.

_**Complexity Analysis:**_

- The time complexity of this approach is O(n), where n is the number of nodes in the linked list.
This is because the solution iterates through the linked list once in the while loop, processing each node exactly once.

- The space complexity of this approach is O(1), which means it uses constant space.
It only requires a few pointers (odd, even, and evenHead) to rearrange the nodes within the linked list.
The space used by these pointers does not depend on the size of the linked list and remains constant regardless of the input size.

<hr>

### C++ Solution:

```cpp

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenHead = even;

        while (even != NULL && even -> next != NULL) {
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        

        odd -> next = evenHead;
        return head;
    }
};

```
