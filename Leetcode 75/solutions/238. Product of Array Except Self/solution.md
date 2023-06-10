## 238. Product of Array Except Self

### Problem Description

Given an integer array ```nums```, return an array ```answer``` such that ```answer[i]``` is equal to the product of all the elements of ```nums``` except ```nums[i]```.

The product of any prefix or suffix of ```nums``` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in ```O(n)``` time and without using the division operation.

Example 1:
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

Example 2:
```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

Constraints:

- ```2 <= nums.length <= 105```
- ```-30 <= nums[i] <= 30```
- The product of any prefix or suffix of ```nums``` is **guaranteed** to fit in a **32-bit integer**.

<hr>

### Approach:

1. Initialize variables:
   - `n` is the size of the input array `nums`.
   - `answer` is an empty vector of size `n` which will store the final result.
   - `product` is initialized to 1, which will store the product of all non-zero elements in `nums`.
   - `zeroCount` will keep track of the number of zeros encountered in `nums`.

2. Calculate the product of the whole array (ignoring zeros):
   - Iterate through each element of `nums`.
   - If the current element is not zero, multiply it with `product`.
   - If the current element is zero, increment `zeroCount` by 1.

3. Calculate `answer[i]` by dividing `product` by `nums[i]` (excluding zeros):
   - Iterate through each element of `nums` again.
   - If the current element is not zero, two conditions are checked:
     - If `zeroCount` is greater than 0 (meaning there is at least one zero in `nums`), set `answer[i]` to 0. This is because dividing by zero is undefined.
     - If `zeroCount` is 0, set `answer[i]` to `product / nums[i]`.
   - If the current element is zero, check if `zeroCount` is equal to 1. If so, set `answer[i]` to `product`. This means there is only one zero in `nums`, and all other elements are non-zero, so the product will be `product`.

4. Return the `answer` vector.

The code follows a two-pass approach, with the first pass calculating the product of all non-zero elements and counting the number of zeros encountered. In the second pass, it computes the individual answer values based on the product and zero count, handling the division by zero case appropriately.

The code aims to solve the problem in O(n) time complexity, where n is the size of the input array.

### C++ Solution:

```cpp

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        int product = 1;
        int zeroCount = 0;
        
        // Step 1: Get the product of the whole array (ignoring zeros)
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                product *= nums[i];
            else
                zeroCount++;
        }
        
        // Step 2: Calculate answer[i] by dividing product by nums[i] (excluding zeros)
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (zeroCount > 0)
                    answer[i] = 0;  // If there is at least one zero in the array
                else
                    answer[i] = product / nums[i];
            } else {
                if (zeroCount == 1)
                    answer[i] = product;
            }
        }
        
        return answer;
    }
};

```
