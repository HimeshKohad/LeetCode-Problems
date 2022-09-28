class Solution {
    public int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        
        if (n < 10){
            return 0; //Since sum and product of digits cannot be calculated as there is only one digit.
        }
        
        char[] array = String.valueOf(n).toCharArray();
        int length = array.length;  // Converting the number to a string and then to an array.
        
        for (int i = 0; i < length; i++){
            int dig = array[i] - '0';
            prod = prod * dig;  // Calculating the product of digits
            sum = sum + dig;  // Calculating the sum of digits
        }
        return prod - sum;  // Return the difference of product and sum of digits
    }
}
