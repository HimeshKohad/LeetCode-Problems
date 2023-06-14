## 334. Increasing Triplet Subsequence

### Problem Description

Given an integer array ```nums```, 
return ```true``` if there exists a triple of indices ```(i, j, k)``` such that ```i < j < k``` and ```nums[i] < nums[j] < nums[k]```. 
If no such indices exists, return ```false```.

Example 1:
```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
```

Example 2:
```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
```

Example 3:
```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```

Constraints:

- ```1 <= nums.length <= 5 * 105```
- ```-231 <= nums[i] <= 231 - 1```

<hr>

### Approach 1:

_**C++ Solution:**_

```cpp

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if (nums.size() < 3) return false;

        int left = INT_MAX;
        int mid = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) return true;

            else if (nums[i] > left && nums[i] < mid) 
                mid = nums[i];

            else if (nums[i] < left)
                left = nums[i];
        }

        return false;
    }
};

```

- It checks if the size of the input array nums is less than 3. If so, it returns false because it's not possible to have an increasing triplet subsequence with fewer than three elements.

- It initializes two variables left and mid with the maximum possible integer value (INT_MAX). These variables will be used to track the potential increasing subsequence.

- It iterates through the elements of the array nums.

- For each element nums[i], it performs the following comparisons:

    a. If nums[i] is greater than mid, it means we have found an increasing triplet subsequence (left < mid < nums[i]), so it returns true.

    b. If nums[i] is greater than left and less than mid, it updates the value of mid to nums[i]. This is because we have found a potential candidate for the middle element of the triplet subsequence.

    c. If nums[i] is less than left, it updates the value of left to nums[i]. This is because we have found a potential candidate for the first element of the triplet subsequence.

- If the loop completes without finding an increasing triplet subsequence, it returns false.

This approach works because it maintains two variables, left and mid, which represent the smallest and second smallest elements in a potential increasing triplet subsequence. As it iterates through the array, it keeps updating these variables accordingly. If it encounters an element greater than mid, it means an increasing triplet subsequence exists and returns true. Otherwise, it returns false if the loop completes without finding such a subsequence.

Note that this approach assumes that there is no integer overflow in the array, as it initializes left and mid with INT_MAX. Also, it assumes that the input array contains only integers.

<hr>

### Approach 2:

_**C++ Solution:**_

```cpp

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if (nums.size() < 3) return false;

        int left = INT_MAX;
        int mid = INT_MAX;

        // Optimizing the if-else conditions
        for (int num : nums) {
            if (num <= left) left = num; // 'left' will be the 1st element

            else if (num <= mid) mid = num; // if 'num > left' && 'num <= mid' then mid will be second element

            else return true; // It means 'num > left' && 'num > mid' --> We have found the increasing triplet
        }

        return false;
    }
};

```

Q. Can you tell the difference between the first and second approach? Which one is better?

- Well both the approaches are efficient solutions for the problem but the second approach would be considered slightly better.
- This is because the second solution uses a more straightforward loop structure (evident from the comments) and avoids nested if statements, making the code easier to understand and maintain.

_**Explaining the second solution:**_
- In Approach 2, the loop uses a simplified form of iteration, using a range-based for loop that directly assigns each element of nums to the variable num.
- It performs the comparisons in a different order compared to Approach 1, but the logic remains the same.
- It checks if num is less than or equal to left, updates left accordingly, then checks if num is less than or equal to mid and updates mid accordingly.
- If an increasing triplet subsequence is found, it immediately returns true.
- The code is concise and has a cleaner control flow since there are no nested if statements.

Both approaches provide efficient solutions to the problem, and the choice between them would not significantly affect 
the overall performance or correctness of the code.
