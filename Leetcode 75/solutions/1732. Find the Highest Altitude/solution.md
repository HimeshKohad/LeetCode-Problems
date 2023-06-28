## 1732. Find the Highest Altitude

### Problem Description

There is a biker going on a road trip. The road trip consists of ```n + 1``` points at different altitudes. 
The biker starts his trip on point ```0``` with altitude equal ```0```.

You are given an integer array ```gain``` of length ```n``` where ```gain[i]``` is the net gain in altitude between points ```i```​​​​​​ and ```i + 1``` for all ```(0 <= i < n)```. 
Return the **highest altitude** of a point.

**Example 1:**
```
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
```

**Example 2:**
```
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
```

**Constraints:**

- ```n == gain.length```
- ```1 <= n <= 100```
- ```-100 <= gain[i] <= 100```

<hr>

### Approach (Prefix Sum):

_**Step 1: Initialize variables**_

```
int prefix = 0;
int maxSum = 0;
```

We start by initializing two variables, prefix and maxSum. prefix will store the running sum of altitudes, and maxSum will keep track of the highest altitude encountered so far.

_**Step 2: Iterate over the altitudes**_

```
for (auto it: gain) {
    prefix = prefix + it;
    maxSum = max(maxSum, prefix);
}
```

Here, we use a loop to iterate over each element it in the gain array, which represents the altitude gain at each point.

_**Step 3: Calculate the prefix sum**_

``` prefix = prefix + it; ```

Inside the loop, we update the prefix variable by adding the current altitude gain (it) to the previous sum. This step is crucial for maintaining the running sum.

_**Step 4: Update the maximum altitude**_

``` maxSum = max(maxSum, prefix); ```

We compare the current prefix sum with the maxSum value. If the prefix sum is greater, it means we have encountered a new highest altitude so far. We update maxSum accordingly.

_**Step 5: Return the highest altitude**_

``` return maxSum; ```

After iterating over all the altitudes, we return the maxSum value, which represents the highest altitude reached during the journey.

<hr>

### C++ Solution:

```cpp

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix = 0;
        int maxSum = 0;

        for (auto it: gain) {
            prefix = prefix + it;
            maxSum = max(maxSum, prefix);
        }

        return maxSum;
    }
};

```

