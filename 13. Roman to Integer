public class Solution {
    public int romanToInt(String S) {
        int ans = 0, num = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) == 'I') {
                System.out.print(num = 1);
            } else if (S.charAt(i) == 'V') {
                System.out.print(num = 5);
            } else if (S.charAt(i) == 'X') {
                System.out.print(num = 10);
            } else if (S.charAt(i) == 'L') {
                System.out.print(num = 50);
            } else if (S.charAt(i) == 'C') {
                System.out.print(num = 100);
            } else if (S.charAt(i) == 'D') {
                System.out.print(num = 500);
            } else if (S.charAt(i) == 'M') {
                System.out.print(num = 1000);
            } else {
                System.out.println("Error");
            }
            if (4 * num < ans)
                ans -= num;
            else
                ans += num;
        }
        return ans;
    }

}
