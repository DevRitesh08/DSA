#include<bits/stdc++.h>
using namespace std;

void PrintVec(vector<int> &v)
{
    cout<<"size of vector : "<<v.size()<<endl ;// TIME COMPLEXITY OF v.size() is O(1) .
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<< v[i]<<" ";
    }
    cout<<endl ;
}

// in this both rows and columns are dynamic in nature !!

int main()
{
    int N ;
    cout<<"Enter number of vector : ";
    cin>>N;

    vector<vector<int>> vec1 ;

    // input vector of vectors
    for(int i = 0 ; i < N ; i++)
    {
        int n ;
        cout<<"enter size of vector "<<i+1 <<": ";
        cin>>n;
        // temporary vector to store elements and then to tranfer in vov
        vector<int> temp ;
        // input a vector
        cout<<"enter vector : ";
        for(int j = 0 ; j < n ; j++)
        {
            int x ;
            cin>>x;
            //vec1[i].push_back(x); cam't do this in this case
            temp.push_back(x);
        }

        vec1.push_back(temp);
    }

    vec1[0].push_back(55);// this adds an element in the first vector

    // vector of vector print
    for(int i = 0 ; i < N ; i++) // instead of N we can do --> vec1.size()
    {
        PrintVec(vec1[i]);
    }

    cout<<vec1[0][1];// this will print the second element of first vector .

}

// we can further make vector of vector of vector or vector of vector of pair ......etc
