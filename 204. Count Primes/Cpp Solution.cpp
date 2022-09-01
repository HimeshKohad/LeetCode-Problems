class Solution {
public:
    int countPrimes(int n) {
        // Sieve of erastotheres
        
        int cnt = 0;
        vector <bool> prime(n + 1, true); // Initially, mark all elements as prime
        
        prime[0] = prime[1] = false;  // 0 and 1 are not prime
        
        for (int i = 0; i < n; i++){  // check all numbers from 2 to n
            if (prime[i]){            // if prime -> increase cnt;
                cnt++;
                
                for (int j = 2*i; j < n; j = j + i){   // If the number is prime then mark all the elements 
                    prime[j] = 0;                      // from the table of that number as non-prime.
                }
            }
        }
        
        return cnt;
    }
};
