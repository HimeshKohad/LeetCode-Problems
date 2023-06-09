## 345. Reverse Vowels of a String

### Problem Description

Given a string ```s```, reverse only all the vowels in the string and return it.

The vowels are ```'a'```, ```'e'```, ```'i'```, ```'o'```, and ```'u'```, and they can appear in both lower and upper cases, more than once.

Example 1:
```
Input: s = "hello"
Output: "holle"
```

Example 2:
```
Input: s = "leetcode"
Output: "leotcede"
```

Constraints:

- ```1 <= s.length <= 3 * 105```
- ```s``` consist of printable ASCII characters.

<hr>

### Approach (Two Pointers):

- The code begins by creating a set named vowels that contains all the lowercase and uppercase vowels. This set will be used to determine whether a character is a vowel or not.

- The code then initializes two variables: s (start) and e (end). s is set to 0, representing the beginning of the string, and e is set to str.size() - 1, representing the end of the string.

- The code enters a loop that continues as long as s is less than e. This loop is used to reverse the vowels in the string.

- Inside the loop, there are two nested while loops. These loops are used to find the next vowel from the start (s) and end (e) positions, respectively.

- The first while loop (while (s < e && !vowels.count(str[s]))) continues until either the end of the string is reached or a vowel is found at the s position. It increments s to move to the next character if the current character is not a vowel.

- Similarly, the second while loop (while (s < e && !vowels.count(str[e]))) continues until either the start of the string is reached or a vowel is found at the e position. It decrements e to move to the previous character if the current character is not a vowel.

- After the two while loops, the code swaps the characters at positions s and e using the swap function, effectively reversing the vowels in the string.

- Finally, the s and e positions are updated by incrementing s and decrementing e using the post-increment (++) and post-decrement (--) operators, respectively.

- The loop continues until s becomes greater than or equal to e, indicating that all the vowels in the string have been reversed.

- Once the loop completes, the modified string is returned.

### C++ Solution:

```cpp

class Solution {
public:
    string reverseVowels(string str) {
        
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for (int s = 0, e = str.size() - 1; s < e;) {
            
            while (s < e && !vowels.count(str[s])) ++s;
            while (s < e && !vowels.count(str[e])) --e;
        
            swap(str[s++], str[e--]);
        }
        
        return str;
    }
};

```
