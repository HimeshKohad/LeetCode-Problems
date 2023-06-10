## 151. Reverse Words in a String

### Problem Description

Given an input string ```s```, reverse the order of the words.

A **word** is defined as a sequence of non-space characters. The words in ```s``` will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that ```s``` may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

Example 2:
```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

Example 3:
```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

Constraints:

- ```1 <= s.length <= 104```
- ```s``` contains English letters (upper-case and lower-case), digits, and spaces ```' '```.
- There is **at least one** word in ```s```.

<hr>

### Approach:

- Inside the reverseWords function, we declare a vector called words to store the individual words, and a string variable word to build each word while iterating through the input string.

- We obtain the length of the input string s using the length() function and store it in the variable n.

- We iterate over the input string s using a for loop, starting from the first character and going up to the last character.

- Inside the loop, we check if the current character is not a space. If it's not a space, we append it to the temporary string word to build the current word.

- If the current character is a space and the previous character (i.e., s[i - 1]) is not a space (to handle multiple spaces between words), it means we have completed a word. We add the word to the words vector and reset the word variable to an empty string for the next word.

- After the loop ends, we check if there's any remaining word in the word variable. If it's not empty, we add it to the words vector. This handles the last word in the input string.

- Now that we have stored all the words in the words vector, we move on to reversing the order of the words.

- We declare a string variable ans to store the reversed words.

- We get the size of the words vector using the size() function and store it in the variable m.

- We use a for loop to traverse the words vector in reverse order, starting from the last word and going up to the first word.

- Inside the loop, we concatenate each word to the ans string.

- Additionally, if the current word is not the first word (i.e., if i > 0), we append an extra space after the word to ensure a single space between words.

- After the loop ends, we have the reversed words stored in the string ans.

- Finally, we return the ans string as the output of the reverseWords function.

### C++ Solution:

```cpp

class Solution {
public:
    string reverseWords(string s) {
        
        vector <string> words;
        string word;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } 
            
            else if (i > 0 && s[i - 1] != ' ') {
                words.push_back(word);
                word = "";
            }
        }

        if (!word.empty()) {
            words.push_back(word);
        }

        string ans = "";
        int m = words.size();
        for (int i = m - 1; i >= 0; i--) {
            ans += words[i];
            if (i > 0) {
                ans += ' '; // Append extra space except for the first word
            }
        }

        return ans;

    }
};

```
