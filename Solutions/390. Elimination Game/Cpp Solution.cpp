class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        if (n <= 5) return 2;

        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};
