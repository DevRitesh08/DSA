// Note: Inside the recursion, the inner loop j will go back up to 1 not up to 0. Because,
// if the j becomes 0, we will try to access the element arr[j-1] i.e. arr[-1] while swapping.
// And so, it will give a runtime error.

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int i, int n) {

    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort(arr, i + 1, n);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, 0, n);
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}


// Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.

// Reason: If we carefully observe, we can notice that the recursion call will occur for
// n times, and for each i, inside the recursive function, the loop j runs from i to 1 i.e. 
// i times. For, i = 1, the loop runs 1 time, for i = 2, the loop runs 2 times, and so on.
// So, the total steps will be approximately the following: 1 + 2 + 3 +……+ (n-2) + (n-1). 
// The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. 
// The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we 
// can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). 
// Here the value of n is N i.e. the size of the array


// Best Case Time Complexity: 

// The best case occurs if the given array is already sorted. And if the given array is already sorted, 
// the recursion calls will only occur and inside the recursive function, the loop will run for
// 0 times(as each element is already present in its correct position). So, our overall time complexity 
// in the best case will boil down to O(N), where N = size of the array.



// Space Complexity: O(N) auxiliary stack space.