## 283. Move Zeroes

### Problem Description

Given an integer array ```nums```, move all ```0```'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

Example 1:
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

Example 2:
```
Input: nums = [0]
Output: [0]
```

**Constraints:**

- ```1 <= nums.length <= 104```
- ```-231 <= nums[i] <= 231 - 1```

<hr> 

### Approach 1 (Brute Force):

According to the question, we have to shift all the zeroes to the end. 
So the easiest and the most brute-force approach I could think of was to use extra space.

So how do we do that?
1. Create a ```vector <int> ans```.
2. First push all the non-zero elements in ```ans```.
3. Now push all the zeroes in ```ans```.

At this point, we have our answer. But it won't let us return the ans array as it is a void function.
So here, we need to equate nums[i] to and[i] using a for loop.

```

for (int i = 0; i < nums.size(); i++) {
            nums[i] = ans[i];
        }

```

So this is the most brute force approach. The code for the same is provided below:

### C++ Solution (Brute Force):

```cpp

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        vector <int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) 
                ans.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) 
                ans.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = ans[i];
        }

    }
};

```

### Complexity Analysis:

Time complexity: O(n), where n is the size of the input vector "nums".

Space complexity: O(n), where n is the size of the input vector "nums".

- Though this solution works, if we look at the question it actually says not to use any extra space.
So we need to optimize our approach 1.

<hr>

### Approach 2 (Optimized):

Now our goal here is to move all the zeros in the vector to the right side while maintaining the relative order of the non-zero elements.

So how do we do that?

- Initialize two variables, "i" and "n". The variable "i" represents the position where the first non-zero value will be placed, and "n" is the size of the input vector "nums".

- Iterate over the vector using a loop variable "j" from 0 to n-1.

- Check if the current element at index "j" is non-zero by comparing "nums[j]" with 0.

- If "nums[j]" is non-zero, it means we have encountered a non-zero element. In that case, we perform a swap operation between "nums[j]" and "nums[i]". This swap moves the non-zero element to the left side of the vector, as "i" represents the position where the next non-zero element should be placed.

- Increment "i" by 1 to move the "i" pointer to the next position for the next non-zero element.

- Repeat steps 3-5 for all elements in the vector.

- After the loop finishes, all non-zero elements have been shifted to the left side of the vector, while their relative order is maintained. The remaining elements at indices greater than "i" are all zeros.

### C++ Solution (Optimized):

```cpp

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;    
        int n = nums.size();
      
        for (int j = 0; j < n; j++){
            
            if (nums[j] != 0){
                swap (nums[j], nums[i]);
                i++;
            }
            
        }
        
    }
};

```

**Note:** The code does not modify the original vector, "```nums```," but rearranges the elements in place.

### Complexity Analysis:

Time complexity: O(n), where n is the size of the input vector "nums".

Space complexity: O(1), as the code uses a constant amount of additional space, regardless of the size of the input vector.
