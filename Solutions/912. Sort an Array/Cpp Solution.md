***Approach 1: Quick Sort (TLE)***
```cpp

class Solution {
public:

    void QuickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {

            int pivot = partition(arr, low, high);
            QuickSort(arr, low, pivot - 1);
            QuickSort(arr, pivot + 1, high);
        }
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j)
        {

            while (arr[i] <= pivot && i <= high - 1)
            {
                i++;
            }

            while (arr[j] > pivot && j >= low)
            {
                j--;
            }

            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[j], arr[low]);

        return j;
    }

    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

```

<hr>

***Approach 2: Heap Sort (Accepted)***

```cpp

class Solution {
    void heapify(vector<int>& arr, int n, int i) {

        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2; 

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]); 
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
  
```
