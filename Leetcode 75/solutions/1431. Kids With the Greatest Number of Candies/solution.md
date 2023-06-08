## 1431. Kids With the Greatest Number of Candies

### Problem Description

There are ```n``` kids with candies. You are given an integer array ```candies```, where each ```candies[i]``` represents the number of candies the ```ith``` kid has, 
and an integer ```extraCandies```, denoting the number of extra candies that you have.

Return a boolean array ```result``` of length ```n```, where ```result[i]``` is ```true``` if, after giving the ```ith``` kid all the ```extraCandies```, 
they will have the **greatest** number of candies among all the kids, or ```false``` otherwise.

Note that **multiple** kids can have the **greatest** number of candies.

Example 1:
```
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
```

Example 2:
```
Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
```

Example 3:
```
Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
```

Constraints:

- n == candies.length
- 2 <= n <= 100
- 1 <= candies[i] <= 100
- 1 <= extraCandies <= 50

<hr>

### Brute Force Approach:

- The code begins by declaring a vector named ans, which will store the results (true or false) for each child.

- The first loop is used to iterate through the candies vector, representing each child.

- Inside the first loop, a boolean variable named test is declared and initialized as false. This variable will be used to determine whether the current child can have the greatest number of candies.

- The second loop is used to compare the current child's candy count with the counts of other children. It iterates through the candies vector again, representing each other child.

- For each iteration of the second loop, the code checks if the current child's candy count plus the extraCandies is less than the candy count of the other child.

- If this condition is true for any other child, it means that the current child cannot have the greatest number of candies. In this case, the test variable is set to true, and the inner loop is terminated using the break statement.

- After the inner loop completes, the code checks the value of the test variable.

- If test is true, it means that the current child cannot have the greatest number of candies. In this case, the code adds false to the ans vector using the push_back function.

- If test is false, it means that the current child can have the greatest number of candies. In this case, the code adds true to the ans vector using the push_back function.

- Finally, the ans vector containing the results for each child is returned.

### C++ Solution

```cpp

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> ans;

        for (int i = 0; i < candies.size(); i++) {
            bool test = false;

            for (int j = 0; j < candies.size(); j++) {
                if (candies[i] + extraCandies < candies[j]) {
                    test = true;
                    break;
                }
            }

            if (test) {
                ans.push_back(false);
            }

            else {
                ans.push_back(true);
            }
        }

        return ans;
    }
};

```

**Time Complexity:** O(n<sup>2</sup>)

**Space Complexity:** O(n)

<hr>

### Optimized Approach:

- The code starts by declaring a vector called ans, which will store the results (true or false) for each child.

- An integer variable maxValue is initialized with the minimum possible value using the INT_MIN constant. This variable will hold the maximum candy count among all the children.

- The first loop is used to find the maximum candy count. It iterates through the candies vector, and at each iteration, the max function is used to update the maxValue variable if the current candy count is greater than the current maximum.

- After finding the maximum candy count, the second loop is used to iterate through the candies vector again.

- For each child, the code checks if their current candy count plus the extraCandies is greater than or equal to the difference between the maximum candy count (maxValue) and extraCandies. This comparison is done to determine if the current child can have the greatest number of candies.

- If the condition is true, it means the current child can have the greatest number of candies. In this case, the code adds true to the ans vector using the push_back function.

- If the condition is false, it means the current child cannot have the greatest number of candies. In this case, the code adds false to the ans vector using the push_back function.

- Finally, the ans vector containing the results for each child is returned.

### C++ Solution

```cpp

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> ans;

        int maxValue = INT_MIN;

        for (int i = 0; i < candies.size(); i++) {
            maxValue = max(maxValue, candies[i]);
        }

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] >= abs(maxValue - extraCandies)) {
                ans.push_back(true);
            }

            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

```

**Time Complexity:** O(n)

**Space Complexity:** O(n)

