## Problem Statement: Generate all Subarrays
Given an array of integers, your task is to generate all possible subarrays of the given array.

### Input
An array of integers arr (1 <= |arr| <= 10^3), where |arr| denotes the number of elements in the array. Each element of the array is an integer.

### Output
A list of all possible subarrays of the given array.

### Example

#### Input

```md
arr = [1, 2, 3]
```

#### Output

```md
[
  [1],
  [1, 2],
  [1, 2, 3],
  [2],
  [2, 3],
  [3]
]
```

<hr>

## Brute Approach:

To generate all possible subarrays, we use a brute-force approach with two nested loops. 
The outer loop iterates over the starting index of the subarray, and the inner loop iterates over the ending index. 
By fixing the starting and ending points, we can consider all subarrays within these bounds.

### Steps:
1. Outer Loop (Starting Index):
   
    - Initialize a loop variable i from 0 to the size of the array.
    - i represents the starting index of the subarray.

2. Inner Loop (Ending Index):
   
    - Initialize another loop variable j from i to the size of the array.
    - j represents the ending index of the subarray.

3. Print Subarray Elements:
   
    - Within the nested loops, print the elements of the subarray from index i to j.
    - Utilize a separate function printSubarray to encapsulate the printing logic.

<br>

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Print subarray elements within the given range.
 *
 * @param arr the input array
 * @param n the size of the array
 * @param i the start index of the subarray
 * @param j the end index of the subarray
 *
 * @return void
 *
 * @throws None
 */
void printSubarrays(vector<int> arr, int i, int j) {
    for(int k = i; k <= j; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

/**
 * Generates all subarrays of the given array.
 *
 * @param arr the input array
 * @param n the size of the array
 *
 * @return void
 *
 * @throws None
 */
void generateSubarrays(vector<int> arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            printSubarrays(arr, i, j);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    generateSubarrays(arr, n);
    return 0;
}
```

This brute-force approach provides a straightforward way to generate all subarrays, but it may not be optimal for large input sizes. 

<hr>

## Optimal Approach:

The optimal solution involves realizing that the number of subarrays for each element is equal to the length of the remaining array. 
We can calculate this directly without the need for multiple nested loops and iterations.

Let's break down the concept of "remaining length":

- **Outer Loop (i):** The outer loop iterates over each element of the array, considering it as the starting point of the subarray.

- **Inner Loop (len):** The inner loop iterates over different lengths of subarrays (`len`). The maximum possible length is the remaining elements in the array after the current starting index (`n - i`).

- **Print Subarray:** The nested loop prints the subarray of length `len` starting from the current index `i`. This loop iterates over the elements within the calculated subarray length.

By adjusting the length of the subarray based on the remaining elements after the current starting index, we avoid unnecessary iterations and achieve a more efficient solution.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Generates all subarrays of the given array and prints each subarray.
 *
 * @param arr The input array.
 *
 * @return void
 */
void generateSubarrays(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int remainingLength = n - i;
        for (int len = 1; len <= remainingLength; ++len) {
            for (int j = i; j < i + len; ++j) {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    generateSubarrays(arr);

    return 0;
}
```

In the optimal solution, although there's still a nested loop, we've reduced the number of nested loops compared to the brute-force approach. 
The outer loop iterates over each element, and the inner loop extends the subarray based on the remaining length. 
This results in a more efficient solution with reduced time complexity, especially for large input sizes.
