'''
    class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length() != t.length()) 
            return false;
        
        int n = s.length();
        
        char s1[] = s.toCharArray();   // Convert the string to char array
        char t1[] = t.toCharArray();
        
        Arrays.sort(s1);   // Sort the arrays
        Arrays.sort(t1);
        
        for ( int i = 0; i < n; i++ ){    // If both sorted arrays are equal --> return true
            if( s1[i] != t1[i] ) return false;
        }
        return true;
    }
}
'''

Time Complexity: O(nlogn)
Space Complexity: O(n)
