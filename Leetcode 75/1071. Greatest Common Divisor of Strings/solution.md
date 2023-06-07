## 1071. Greatest Common Divisor of Strings

### Problem Description

For two strings ```s``` and ```t```, we say "```t``` divides ```s```" if and only if ```s = t + ... + t``` (i.e., t is concatenated with itself one or more times).

Given two strings ```str1``` and ```str2```, return the largest string ```x``` such that ```x``` divides both ```str1``` and ```str2```.

Example 1:

```
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
```

Example 2:

```
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
```

Example 3:

```
Input: str1 = "LEET", str2 = "CODE"
Output: ""
```

Constraints:

- 1 <= str1.length, str2.length <= 1000
- str1 and str2 consist of English uppercase letters.

<hr>

### Approach:

```
1. The code begins by concatenating s1 and s2 using the + operator and comparing it with the concatenation of s2 and s1. If they are not equal, it means that s1 and s2 do not have a common divisor. In such a case, the code returns an empty string "".

2. If the concatenation of s1 and s2 is equal to the concatenation of s2 and s1, it means that s1 and s2 have a common divisor. The code proceeds to calculate the GCD of the lengths of s1 and s2 using the gcd function.

3. The gcd function calculates the greatest common divisor using the Euclidean algorithm. It takes the sizes of s1 and s2 as inputs and returns their GCD. Since the gcd function operates on the sizes of the strings, it doesn't depend on the actual characters in the strings and takes constant time.

4. Finally, the code uses the s1.substr(0, gcd(s1.size(), s2.size())) function to return a substring of s1 starting from index 0 and having a length equal to the calculated GCD. This substring represents the longest common divisor of s1 and s2.

In summary, the approach checks if the concatenation of s1 and s2 is equal to the concatenation of s2 and s1 to determine if the strings have a common divisor. If they do, it calculates the GCD of their lengths and returns the corresponding substring from s1. Otherwise, it returns an empty string.
```

### C++ Solution:

```cpp

class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1 + s2 != s2 + s1){
            return "";
        }
        
        return s1.substr(0, gcd(s1.size(), s2.size()));
    }
};

```

