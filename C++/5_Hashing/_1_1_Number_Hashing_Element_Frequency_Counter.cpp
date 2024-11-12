#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout<<"Enter size of array : ";
    cin >> n;
    int arr[n];
    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cout<<"Enter number of queries to search : ";
    cin >> q;
    cout<<"enter queries : ";
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}