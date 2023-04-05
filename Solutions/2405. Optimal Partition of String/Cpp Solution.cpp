class Solution {
public:
    int partitionString(string s) {
        
        int res = 1;

        vector <int> cnt(26);

        for (auto it : s){
            if (cnt [it - 'a']){
                cnt = vector <int> (26);
                res++;
            }

            cnt [it - 'a']++;
        }

        return res;
    }
};
