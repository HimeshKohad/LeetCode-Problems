***Approach-1: Linerar Search***

``` cpp

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++){
            if (nums[i] == target) return true;
        }
      
        return false;
    }
};

```
---

***Approach-2: Binary Search***

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;
        
        while (leftIdx <= rightIdx) {
            int midIdx = rightIdx + (leftIdx-rightIdx) / 2;
            if (nums[midIdx] == target) {
                return true;
            }
            if (nums[leftIdx] <= nums[midIdx]) { // left is sorted
                if (target >= nums[leftIdx] && target < nums[midIdx]) {
                    rightIdx = midIdx - 1;
                } else {
                    leftIdx = midIdx + 1;
                }
            } else { // right is sorted
                if (target > nums[midIdx] && target <= nums[rightIdx]) {
                    leftIdx = midIdx + 1;
                } else {
                    rightIdx = midIdx - 1;
                }
            }
            //return true;
        }
        return false;


    }
};

```
