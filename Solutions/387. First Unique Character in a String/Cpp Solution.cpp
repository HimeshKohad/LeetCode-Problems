class Solution {
public:
    int firstUniqChar(string s) {
        
        int arr[100000] = {0};
        
        for (char c : s) 
            arr[c]++;
        
        for (int i = 0; i < s.size(); i++){
            if (arr[s[i]] == 1) 
                return i;
        }
        
        return -1;
    }
};
