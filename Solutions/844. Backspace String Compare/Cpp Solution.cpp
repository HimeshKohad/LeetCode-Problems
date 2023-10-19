class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1 = "", ans2 = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if (!ans1.empty()) { // Check if ans1 is not empty before popping
                    ans1.pop_back();
                }
            }
            else {
                ans1.push_back(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++) {
            if(t[i] == '#') {
                if (!ans2.empty()) { // Check if ans2 is not empty before popping
                    ans2.pop_back();
                }
            }
            else {
                ans2.push_back(t[i]);
            }
        }

        return (ans1 == ans2);
    }
};
