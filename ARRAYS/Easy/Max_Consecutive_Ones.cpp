#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    int max_count = 0;
    for(int i = 0 ; i < n ;i++)
    {
        if(arr[i] == 1)
        {
            count++;
            max_count = max(max_count,count); //time complexity of max function is O(1)
        }
        else
        {
            count = 0;
        }
    }

    cout<<"The maximum number of consecutive ones are : "<<max_count;

    return 0;
}

// The above code has a time complexity of O(n) and space complexity of O(1) .