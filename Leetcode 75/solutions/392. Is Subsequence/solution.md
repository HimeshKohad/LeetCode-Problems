## 392. Is Subsequence

### Problem Description

Given two strings ```s``` and ```t```, return ```true``` if ```s``` is a subsequence of ```t```, or ```false``` otherwise.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. 
(i.e., ```"ace"``` is a subsequence of ```"abcde"``` while ```"aec"``` is not).

Example 1:
```
Input: s = "abc", t = "ahbgdc"
Output: true
```

Example 2:
```
Input: s = "axc", t = "ahbgdc"
Output: false
```

**Constraints:**

- ```0 <= s.length <= 100```
- ```0 <= t.length <= 104```
- ```s``` and ```t``` consist only of lowercase English letters.

<hr>

### Approach 1:

_**C++ Solution:**_

```cpp

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length(); 
        int m = t.length();
        
        int j = 0; 
        
        for (int i = 0; i < m and j < n; i++)
            if (s[j] == t[i])
                j++;
        
        return (j == n);
    }
};

```

_**Explanation:**_

Let's break down the code and explain its approach step by step:

1. Initialize variables: 
   - `n` is the length of string `s`.
   - `m` is the length of string `t`.
   - `j` is a pointer that will traverse string `s`.

2. Start a loop: 
   - Initialize `i` as 0.
   - Continue the loop as long as `i` is less than `m` (length of `t`) and `j` is less than `n` (length of `s`).

3. Check character equality:
   - Inside the loop, compare the characters at indices `j` and `i` of strings `s` and `t`, respectively.
   - If the characters are equal, it means we have found a match.
   - Increment `j` to move to the next character in `s`.

4. Continue looping:
   - After the comparison, regardless of whether there was a match or not, increment `i` to move to the next character in `t`.

5. Repeat steps 3-4 until the loop condition is met.

6. Check if `s` is a subsequence:
   - After the loop ends, we need to check whether we have traversed all characters in `s` (i.e., `j == n`).
   - If `j` is equal to `n`, it means we successfully traversed all characters in `s`, and hence, `s` is a subsequence of `t`.
   - Return `true` in this case.

7. Return the result:
   - If the loop ended before `j` reached `n`, it means we were not able to traverse all characters in `s`.
   - In this case, return `false` as `s` is not a subsequence of `t`.

To summarize, the code iterates over the characters of `s` and `t` simultaneously. 
It incrementally moves through `t` and checks for matches with the characters in `s`. 
If all characters in `s` are found in `t` in the same order, the code returns `true`, indicating that `s` is a subsequence of `t`.
