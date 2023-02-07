class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int cnt = countDigits(nums[i]);

            if (cnt % 2 == 0) {
                sum++;
            }
        }

        return sum;
    }

private:
    int countDigits(int n) {
        int count = 0;

        while (n > 0) {
            n = n / 10;
            count++;
        }

        return count;
    }
};
