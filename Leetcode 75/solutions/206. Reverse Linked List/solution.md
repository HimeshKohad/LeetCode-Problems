## 206. Reverse Linked List

### Problem Description

Given the ```head``` of a singly linked list, reverse the list, and _return the reversed list_.

Example 1:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/82152aec-cda0-4fb6-8fad-3e203aab7899)

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

Example 2:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/6034d358-1bf7-457d-81d7-f6b73dc01240)

```
Input: head = [1,2]
Output: [2,1]
```

Example 3:
```
Input: head = []
Output: []
```

Constraints:

- The number of nodes in the list is the range ```[0, 5000]```.
- ```-5000 <= Node.val <= 5000```

<hr>

### Approach

## Approach Explanation - Reversing a Linked List

The given code implements a recursive approach to reverse a linked list. Let's break down the steps involved:

1. **`void reverse(ListNode* &head, ListNode* curr, ListNode* prev)`**
   - This is a recursive function that takes three parameters:
     - `head`: a reference to the head of the linked list.
     - `curr`: the current node being processed.
     - `prev`: the previous node of the current node.
   - The function aims to reverse the linked list using recursion.

2. **`if (curr == NULL)`**
   - This condition checks if the current node is `NULL`, indicating that we have reached the end of the linked list.

3. Inside the `if` condition:
   - `head = prev;`
     - If the end of the list is reached, we update the `head` parameter to point to the last node, which is `prev`.
     - This step effectively reverses the direction of the linked list.
   - `return;`
     - We exit the current recursive call as the end of the list has been reached.

4. **`ListNode* forward = curr -> next;`**
   - If the end of the list has not been reached, we store the next node (`curr->next`) in the `forward` variable.
   - This is done to preserve the reference to the next node before we reverse the link between `curr` and `prev`.

5. **`reverse(head, forward, curr);`**
   - We make a recursive call to the `reverse` function, passing the updated parameters:
     - `head` remains the same as we need to keep track of the reversed list's head.
     - `forward` becomes the new `curr`, as we move one step forward in the list.
     - `curr` becomes the new `prev`, as we need to reverse the link between `curr` and `prev`.

6. **`curr -> next = prev;`**
   - Once we return from the recursive call, we update the next pointer of the current node (`curr->next`) to point to the previous node (`prev`).
   - This step effectively reverses the link between `curr` and `prev`, as `prev` becomes the next node in the reversed list.

7. **`ListNode* reverseList(ListNode* head)`**
   - This function serves as the entry point for the reverse operation.
   - It takes the original head of the linked list as an input parameter.

8. **`ListNode* curr = head;`**
   - We initialize the `curr` pointer to the original head of the linked list.

9. **`ListNode* prev = NULL;`**
   - We initialize the `prev` pointer to `NULL`, as there is no previous node for the original head.

10. **`reverse(head, curr, prev);`**
    - We call the `reverse` function with the original head, `curr`, and `prev` as parameters to start the reversal process.

11. **`return head;`**
    - Finally, we return the updated head of the reversed list.

That's it! This approach uses a recursive approach to reverse a linked list. It modifies the original list in place by updating the next pointers of each node.

---

### Complexity Analysis:

_**Time Complexity Analysis**_
The time complexity of the code is determined by the number of nodes in the linked list. Let's denote n as the number of nodes in the list.

The reverseList function makes a single call to the reverse function, which performs a recursive reversal of the linked list. The recursion traverses each node once, resulting in a linear time complexity of O(n).

_**Space Complexity Analysis**_
The space complexity of the code is determined by the depth of the recursive call stack. In other words, it depends on the maximum number of recursive calls that can be active at any given time.

Since the recursive calls are tail recursive (i.e., the recursive call is the last operation in the function), the space complexity can be optimized to O(1) by using tail recursion elimination. This means that no additional space is required beyond the function parameters and local variables.

<hr>

### C++ Solution:

```cpp

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

```
