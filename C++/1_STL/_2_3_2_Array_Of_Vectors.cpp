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


int main()
{
    vector<int> vec[10]; // this means an array of 10 vectors .

    int N;
    cout<<"Enter number of vectors to input : ";
    cin>>N;
    vector<int> vec1[N] ;
    // input array of vectors
    for(int i = 0 ; i < N ; i++)
    {
        int n ;
        cout<<"enter size of vector "<<i+1 <<": ";
        cin>>n;
        // input a vector
        cout<<"enter vector : ";
        for(int j = 0 ; j < n ; j++)
        {
            int x ;
            cin>>x;
            vec1[i].push_back(x);
        }
    }

    // array of vector print
    for(int i = 0 ; i < N ; i++)
    {
        PrintVec(vec1[i]);
    }

    // it is just like 2-D vector , but here number of rows are fixed but columns are dynamic in size .
    cout<<vec1[0][1];// this will print the second element of first vector .
}

// as arrays are of fixed size so here N remains constant once initialized so to solve this we have vector of vector .