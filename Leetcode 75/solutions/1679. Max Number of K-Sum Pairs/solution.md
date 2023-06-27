## 1679. Max Number of K-Sum Pairs

### Problem Description

You are given an integer array ```nums``` and an integer ```k```.

In one operation, you can pick two numbers from the array whose sum equals ```k``` and remove them from the array.

_Return the maximum number of operations you can perform on the array._

**Example 1:**
```
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
```

**Example 2:**
```
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
```

**Constraints:**

- ```1 <= nums.length <= 105```
- ```1 <= nums[i] <= 109```
- ```1 <= k <= 109```

<hr>

### Approach 1 (Two Pointers):

1. Sort the array nums in ascending order. Sorting the array allows us to efficiently manipulate the pointers.

2. Initialize two pointers, s and e, to the start and end of the sorted array, respectively. These pointers will be used to traverse the array.

3. Create a variable cnt and set it to 0. This variable will store the count of pairs that sum up to the given value k.

4. Enter a while loop that continues as long as s is less than e. This loop ensures that the pointers do not cross each other.

5. Inside the while loop:

    - Check if the sum of nums[s] and nums[e] is equal to k.
    - If the sum is equal to k, increment the count cnt to indicate that a pair is found.
    - Move both pointers towards the center by incrementing s and decrementing e.
    - If the sum of nums[s] and nums[e] is less than k, increment s to consider a larger value.
    - If the sum of nums[s] and nums[e] is greater than k, decrement e to consider a smaller value.
    - Repeat steps 5 until s becomes greater than or equal to e, indicating that all possible pairs have been considered.

6. Return the value of cnt, which represents the maximum number of pairs that sum up to k.

### C++ Solution:

```cpp

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort (nums.begin(), nums.end());
        int s = 0, e = nums.size() - 1;
        int cnt = 0;

        while (s < e) {
            if (nums[s] + nums[e] == k) {
                cnt++;
                s++;
                e--;
            }

            else if (nums[s] + nums[e] < k) {
                s++;
            }

            else e--;
        }

        return cnt;
    }
};

```

### Complexity Analysis:

_**Time Complexity:**_

Sorting the array nums takes O(n log n) time complexity, where n is the size of the array.
The while loop runs until s becomes greater than or equal to e. In the worst case, both pointers traverse the entire array, resulting in O(n) iterations.
Each iteration of the loop involves constant time operations such as element comparisons, pointer updates, and increment/decrement operations.
Therefore, the overall time complexity is dominated by the sorting step, resulting in ```O(n log n)``` time complexity.


_**Space Complexity:**_

The space complexity is determined by the sorting algorithm used.
If an in-place sorting algorithm like Quicksort or Heapsort is used, the space complexity is O(1) as it does not require any additional memory.
If a sorting algorithm like Mergesort is used, it typically requires O(n) additional space for temporary arrays during the sorting process. However, the given code snippet does not use any additional space apart from the input array.
Hence, the space complexity in this case is ```O(1)```.


_In summary, the time complexity of the two-pointer approach is ```O(n log n)```, where n is the size of the array, and the space complexity is ```O(1)```._

<hr>

### Approach 2 (HashMap):

1. Create an unordered_map mp to store the frequency count of elements encountered in the array.

2. Create a variable cnt and set it to 0. This variable will store the count of pairs that sum up to the given value k.

3. Iterate through the elements of the array nums using a for loop.

    - Check if k - nums[i] is present in the unordered_map mp. This represents the complement needed to form a pair that sums up to k.
      - If the complement is found, decrement its count in mp and increment cnt to indicate that a pair is found.
      - Check if the count of the complement becomes zero. If it does, remove it from mp using the erase function.
    - If the complement is not found in mp, it means nums[i] is a potential element that can form a pair. Increment its count in mp.
    
4. Repeat step 3 for all elements in the array.

5. Return the value of cnt, which represents the maximum number of pairs that sum up to k.


### C++ Solution:

```cpp

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(k-nums[i]) != mp.end()){
                mp[k - nums[i]]--;
                cnt++;

                if (mp[k - nums[i]] == 0) {
                    mp.erase(k - nums[i]);
                }
            }

            else {
                mp[nums[i]]++;
            }
        }

        return cnt;
    }
};

```

### Complexity Analysis:

_**Time Complexity:**_

The code iterates through each element of the array nums once using a for loop, resulting in O(n) iterations, where n is the size of the array.
Inside the loop, the unordered_map operations like finding an element (find) and erasing an element (erase) take constant time on average.
Therefore, the overall time complexity is ```O(n)```.


_**Space Complexity:**_

The space complexity is determined by the usage of the unordered_map mp.
In the worst case, if all elements in the array are unique, the unordered_map mp will store n key-value pairs, where n is the size of the array. This will require O(n) additional space.
In the best case, if there are no pairs that sum up to k, the unordered_map mp will be empty.
Therefore, the space complexity is ```O(n)``` in the ```worst case``` and ```O(1)``` in the ```best case```.


In summary, the time complexity of the hashmap approach is ```O(n)```, where n is the size of the array, and the space complexity is ```O(n)``` in the ```worst case``` and ```O(1)``` in the ```best case```.
