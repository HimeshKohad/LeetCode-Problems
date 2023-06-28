## 2095. Delete the Middle Node of a Linked List

### Problem Description

You are given the ```head``` of a linked list. **Delete** the **middle node**, and return the ```head``` of the modified linked list.

The middle node of a linked list of size ```n``` is the ```⌊n / 2⌋th``` node from the start using 0-based indexing, where ```⌊x⌋``` denotes the 
largest integer less than or equal to ```x```.

- For ```n``` = ```1```, ```2```, ```3```, ```4```, and ```5```, the middle nodes are ```0```, ```1```, ```1```, ```2```, and ```2```, respectively.

Example 1:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/8af8702e-5707-43c8-be85-852614b84a75)

```
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.
```

Example 2:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/001e7a9b-d7b5-44c4-b4ee-55f32e1444cc)

```
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
```

Example 3:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/33075d7c-7081-4295-83e0-011564f5562d)

```
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
```

<hr>

### C++ Solution:

```cpp

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head == NULL || head -> next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head -> next -> next;

        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow -> next = slow -> next -> next;
        return head;
    }
};

```
