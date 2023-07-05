## 2130. Maximum Twin Sum of a Linked List

### Problem Description

In a linked list of size ```n```, where ```n``` is even, the ```ith``` node (0-indexed) of the linked list is known as the twin of the ```(n-1-i)th``` node, 
if ```0 <= i <= (n / 2) - 1```.

- For example, if ```n = 4```, then node ```0``` is the twin of node ```3```, and node ```1``` is the twin of node ```2```.
These are the only nodes with twins for ```n = 4```.
The twin sum is defined as the sum of a node and its twin.

Given the ```head``` of a linked list with even length, return the **maximum twin sum** of the linked list.

Example 1:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/23e4ee26-3d4f-4d7d-9579-f49ad535d802)

```
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
```

Example 2:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/6025ad43-f443-4c47-8ed7-eb6db39812a6)

```
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
 ```

Example 3:

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/e257fe43-aef7-48b1-8326-94e69ec542a4)

```
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
```
 

Constraints:

- The number of nodes in the list is an even integer in the range ```[2, 105]```.
- ```1 <= Node.val <= 105```

<hr>

### Approach (Two Pointers): 

1. In this step, we initialize a pointer curr to the head of the linked list and create an empty vector nodes.
We iterate over the linked list and store the values of each node in the vector.
This step essentially converts the linked list into a vector for easier access.

2. After storing the node values in the vector, we initialize two variables i and j.
i represents the start index of the vector, and j represents the end index.
We also initialize maxSum to INT_MIN (the minimum possible integer value) to track the maximum twin sum.

3. We then enter a loop that continues until i is less than j. 
Inside the loop, we calculate the sum of nodes[i] and nodes[j], and update maxSum if the current sum is greater than the previous maximum. 
We then increment i and decrement j to move towards the middle of the vector, checking for the maximum twin sum.

4. Finally, we return the maximum twin sum obtained from the loop.

This code aims to find the maximum sum of pairs of nodes in a linked list, treating the linked list as an array-like structure represented by the vector nodes.

<hr>

_**Complexity Analysis:**_

**Time Complexity:**

The overall time complexity of the code is dominated by the two steps described above, which are both linear. Therefore, the overall time complexity is O(n), where 'n' is the number of nodes in the linked list.

**Space Complexity:**

We use a vector 'nodes' to store the values of the linked list nodes. The space required is proportional to the number of nodes, so the space complexity is O(n).
In summary, the code has a time complexity of O(n) and a space complexity of O(n), where 'n' is the number of nodes in the linked list.

<hr>

### C++ Solution:

```cpp

class Solution {
public:
    int pairSum(ListNode* head) {
        
        vector <int> ans;
        int twinSum = 0;
        int maxSum = 0;

        for (ListNode* i = head; i != NULL; i = i -> next) {
            ans.push_back(i -> val);
        }

        int i = 0, j = ans.size() - 1;

        for (int i = 0; i < ans.size(); i++) {
            twinSum = ans[i] + ans[j];
            maxSum = max(maxSum, twinSum);
            j--;
        }   

        return maxSum;
    }
};

```
