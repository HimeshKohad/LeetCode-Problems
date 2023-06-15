## 443. String Compression

### Problem Description

Given an array of characters ```chars```, compress it using the following algorithm:

Begin with an empty string ```s```. For each group of consecutive repeating characters in ```chars```:

If the group's length is ```1```, append the character to ```s```.
Otherwise, append the character followed by the group's length.
The compressed string ```s``` **should not be returned separately, but instead, be stored in the input character array** ```chars```. 
Note that group lengths that are ```10``` or longer will be split into multiple characters in ```chars```.

After you are done **modifying the input array**, return _the new length of the array_.

You must write an algorithm that uses only constant extra space.

Example 1:
```
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
```

Example 2:
```
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
```

Example 3:
```
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
```

**Constraints:**

- ```1 <= chars.length <= 2000```
- ```chars[i]``` is a lowercase English letter, uppercase English letter, digit, or symbol.

<hr>

### Approach:

1. Initialize variables: 
   - `cnt` (count) to keep track of the number of consecutive occurrences of a character.
   - `ans` as an empty string to store the compressed version of the input string.

2. Append the first character of the input string to `ans` using the `push_back` function.

3. Iterate through the remaining characters of the input string using a for loop, starting from index 1:
   - Check if the current character is the same as the previous character (`chars[i] == chars[i - 1]`).
   - If it is the same, increment the `cnt` variable to keep track of the number of consecutive occurrences of that character.
   - If it is different:
     - Check if `cnt` is greater than 1 (indicating more than one occurrence of the previous character).
       - If it is, append `cnt` to `ans` by converting it to a string using `to_string(cnt)` and concatenating it to `ans`.
     - Reset `cnt` to 1 to start counting the occurrences of the new character.
     - Append the new character to `ans` using the `push_back` function.

4. After the loop ends, there might be a pending count for the last character. Check if `cnt` is greater than 1:
   - If it is, append `cnt` to `ans` by converting it to a string using `to_string(cnt)` and concatenating it to `ans`.

5. Update the `chars` array to contain the compressed version of the string stored in `ans`. Iterate through the characters of `ans` using a for loop:
   - Assign each character of `ans` to the corresponding index in the `chars` array.

6. Return the size of the compressed string (`ans`) as the result.

The overall idea of the approach is to iterate through the input string, count consecutive occurrences of characters, 
and build a compressed version of the string.

### C++ Solution:

```cpp

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int cnt = 1;
        string ans;

        ans.push_back(chars[0]);

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1]) 
                cnt++;

            else {
                if (cnt > 1)
                    ans = ans + to_string(cnt);
                
                cnt = 1;
                ans.push_back(chars[i]);
            }
        }

        if (cnt > 1) 
            ans = ans + to_string(cnt);

        for (int i = 0; i < ans.length(); i++)
            chars[i] = ans[i];

        return ans.size();
    }
};

```
---

### Complexity Analysis

_**Time Complexity Analysis:**_

1. The first for loop iterates through the characters of the input string, which takes O(n) time, where n is the length of the input string.

2. The second for loop iterates through the characters of the compressed string (ans), which also takes O(n) time, where n is the length of the compressed string.

Therefore, the overall time complexity of the code is O(n), where n is the length of the input string.

_**Space Complexity Analysis:**_

1. The ans string is used to store the compressed version of the input string. Its maximum length can be equal to the length of the input string, as in the worst case, there are no repeated characters. Therefore, the space complexity of ans is O(n), where n is the length of the input string.

2. The additional space used by the cnt variable and other temporary variables is constant and does not depend on the input size. Hence, it can be considered as O(1).

Therefore, the overall space complexity of the code is O(n), where n is the length of the input string.
