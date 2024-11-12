#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // temporary array
    int left = low;           // starting index of left half of arr
    int right = mid + 1;      // starting index of right half of arr
    int k = 0;                // index for the temp array

    // storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    // if elements on the left half are still left
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // if elements on the right half are still left
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // transferring all elements from temp to arr
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);       // left half
    mergeSort(arr, mid + 1, high);  // right half
    merge(arr, low, mid, high);     // merging sorted halves
}

int main() {
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
