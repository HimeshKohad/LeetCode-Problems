## 605. Can Place Flowers

### Problem Description

You have a long flowerbed in which some of the plots are planted, and some are not. 
However, flowers cannot be planted in adjacent plots.

Given an integer array ```flowerbed``` containing ```0```'s and ```1```'s, where ```0``` means empty and ```1``` means not empty, and an integer ```n```, 
return ```true``` _if n new flowers can be planted in the ```flowerbed``` without violating the no-adjacent-flowers rule and ```false``` otherwise._


Example 1:
```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

Example 2:
```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

Constraints:

- ```1 <= flowerbed.length <= 2 * 104```
- ```flowerbed[i]``` is ```0``` or ```1```.
- There are no two adjacent flowers in ```flowerbed```.
- ```0 <= n <= flowerbed.length```

<hr>

### Approach:

- The code begins with a check: if the number of flowers to be planted, n, is equal to 0, it means all flowers have already been planted. In this case, the function returns true, indicating that it is possible to place the remaining flowers.

- If n is not 0, the code proceeds to a loop that iterates through the flowerbed vector.

- For each position in the flowerbed, the code checks if the current position contains a 0 (representing an empty spot to plant a flower) and if the adjacent positions (if they exist) are also empty. This condition is checked using the logical operators &&.

- The condition (i == 0 || flowerbed[i - 1] == 0) checks if the current position is the first position in the flowerbed vector or if the previous position contains a 0. This ensures that the left adjacent position is empty.

- The condition (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) checks if the current position is the last position in the flowerbed vector or if the next position contains a 0. This ensures that the right adjacent position is empty.

- If all these conditions are true, it means that a flower can be planted at the current position. The code reduces the number of remaining flowers to be planted, n, by 1 using the pre-decrement operator --.

- After decrementing n, the code checks if n has become 0, indicating that all flowers have been planted. If n is 0, the function returns true, indicating that it is possible to place all the flowers.

- If n is still not 0, it means there are remaining flowers to be planted, and the code marks the current position as planted by changing the value in the flowerbed vector to 1.

- The loop continues until all positions in the flowerbed have been examined.

- Finally, if the loop completes without returning true (indicating that all flowers have been planted), the function returns false, indicating that it is not possible to place all the flowers.

### C++ Solution:

```cpp

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (n == 0) return true;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                --n;

                if (n == 0) return true;

                flowerbed[i] = 1;
            }
        }

        return false;
    }
};

```

**Time Complexity:** O(n)

**Space Complexity:** O(1)
