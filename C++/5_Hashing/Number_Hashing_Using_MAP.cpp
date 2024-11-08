#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int n;
    cout<<"Enter the size of array : ";
    cin >> n;
    int arr[n];
    cout<<"Enter the array elements : ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    //precompute:
    map<int, int> mp;
    for (int i = 0; i < n; i++) 
    {
        mp[arr[i]]++;
    }

    // // iterate over the map: (To print the map )
    // for(auto it : mp)
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }
    

    int q;
    cout<<"Enter number of queries : ";
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetch:
        cout << mp[number] << endl;
    }
    return 0;
}