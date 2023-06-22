## 11. Container With Most Water

### Problem Description

You are given an integer array ```height``` of length ```n```. There are ```n``` vertical lines drawn such that the two endpoints of the ```ith``` line are ```(i, 0)``` and ```(i, height[i])```.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

_Return the maximum amount of water a container can store._

Notice that you may not slant the container.

**Example 1:**

![image](https://github.com/HimeshKohad/LeetCode-Problems/assets/107066424/17be2953-a4cb-4cbb-82a8-44754199769b)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

**Example 2:**
```
Input: height = [1,1]
Output: 1
```

<hr>

### Approach (Two Pointers):

- Initialize variables: The code begins by initializing the variables s and e. The variable s represents the start pointer, which is set to the first index of the height vector. The variable e represents the end pointer, which is set to the last index of the height vector. Additionally, maxArea is initialized as 0 to store the maximum area found.

- Enter a while loop: The loop continues as long as the start pointer s is less than the end pointer e.

- Calculate the new area: The new area is calculated using the formula min(height[s], height[e]) * abs(e - s). The min function returns the minimum value between the heights at indices s and e, representing the height of the container. The width of the container is calculated as the absolute difference between the end pointer e and the start pointer s (abs(e - s)). The product of the height and width gives the new area, which is stored in the variable newArea.

- Update the maximum area: The maximum area (maxArea) is updated by taking the maximum value between the current maximum area and the newly calculated area (max(maxArea, newArea)). This ensures that maxArea always holds the maximum area encountered so far.

- Move the pointers: The code checks if the height at index s is greater than the height at index e. If it is, then the end pointer e is decremented, indicating that we want to explore the possibility of a higher height. This is because the area of the container is limited by the shorter height. Otherwise, if the height at index s is less than or equal to the height at index e, the start pointer s is incremented, indicating that we want to explore the possibility of a higher height at the s index.

- Return the maximum area: After the while loop terminates, the maximum area (maxArea) is returned as the final result.

### C++ Solution:

```cpp

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int maxArea = 0;

        while (s < e) {
            int newArea = (min(height[s], height[e]) * abs(e - s));
            maxArea = max(maxArea, newArea);

            if (height[s] > height[e]) e--;
            else s++;
        }

        return maxArea;
    }
};

```

### Complexity Analysis:

_**Time Complexity:**_
The time complexity of the code is O(n), where n is the size of the input `height` vector. This is because the code uses a two-pointer approach, iterating over the array once and gradually moving the pointers towards each other until they meet. Since each iteration reduces the search space by one, the while loop runs a maximum of n times.

_**Space Complexity:**_
The space complexity of the code is O(1), which means it requires constant space. The code does not use any additional data structures that grow with the input size. It only uses a few integer variables to store indices, heights, and the maximum area, which require constant space regardless of the input size.

In summary, the code has a time complexity of O(n) and a space complexity of O(1).
