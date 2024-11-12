#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }

    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;

}


// The time complexity of this recursive bubble sort algorithm can be analyzed as follows:

// 1. Worst-Case and Average-Case Time Complexity
// For each call to bubble_sort, an iteration over the range [0, n-2] is made, which requires O(n) time. Since bubble_sort is called recursively with n-1 on each subsequent call, it will run approximately n recursive calls. Thus, the total number of comparisons and swaps in the worst case would be:

// O(n) + O(n-1) + O(n-2) + ⋯ + O(1) = O(n(n-1)/2) = O(n^2)

// Therefore, the time complexity is O(n^2) in the worst and average cases.

// 2. Best-Case Time Complexity
// In the best case, if the array is already sorted, the function will still make n-1 recursive calls, each with an O(n) comparison. This recursive implementation does not include an optimization to terminate early if the array is already sorted, so the best-case time complexity remains O(n^2) as well.

// Summary
// Worst-case time complexity: O(n^2)
// Average-case time complexity: O(n^2)
// Best-case time complexity: O(n^2)


// Space Complexity: O(N) auxiliary stack space.