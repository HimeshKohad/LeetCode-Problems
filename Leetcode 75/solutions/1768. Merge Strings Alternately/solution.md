## 1768. Merge Strings Alternately

### Problem Description

You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:

```
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
```

Example 2:

```
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
```

Example 3:

```
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
```

Constraints:

- 1 <= word1.length, word2.length <= 100
- word1 and word2 consist of lowercase English letters.

<hr>

### Approach: 
To merge the strings alternately, we can iterate over both words simultaneously, appending one character from each word to the result string in alternating order. 
If one word is longer than the other, we can simply append the remaining characters from the longer word to the result.

Here's the step-by-step approach:

- Initialize an empty string result to store the merged string.
- Initialize two variables, i and j, to track the current indices of word1 and word2, respectively. Start both indices at 0.
- While i is less than the length of word1 and j is less than the length of word2, do the following:
- Append word1[i] to result.
- Append word2[j] to result.
- Increment i and j by 1.
- If i is less than the length of word1, append the remaining characters of word1 starting from index i to result.
- If j is less than the length of word2, append the remaining characters of word2 starting from index j to result.
- Return the result string.

### C++ Solution

```cpp

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i = 0, j = 0;

        string ans = "";

        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size()) {
                ans.push_back(word1[i++]);
            }

            if (j < word2.size()) {
                ans.push_back(word2[j++]);
            }
        }

        return ans;
    }
};

```
