#include<iostream>
#include<bits/stdc++.h> // to add all header files
using namespace std ;
// types of function void , return , parameterised  and non parameterised

// this one is both parameterised and voi
// void printName (string name)
// {
//     cout<<"hey "<<name<<endl;
// }

// int main()
// {
//     string name;
//     cin>>name;
//     cout<<"enter name : ";
//     printName(name);
//     return 0;

// }

// pass by reference
// void doSth (string &name) // name --> &name
// {
//     name[0] = 't';
//     cout<<name<<endl;
// }

// int main()
// {
//     string name = "taj ";
//     doSth(name);
//     cout<<name<<endl;
//     return 0;

// }

// pass by reference for array no need of & as its default call bu reference
void doSth (int arr[] , int n) // no need of & in array
{
   arr[0] += 100 ;
   cout<<"value inside function : "<<arr[0]<<endl;
}

int main()
{
    int n = 5;
    int arr[5];
    cout<<"enter values of array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    doSth(arr,n);

    cout<<"value inside int main : "<<arr[0];

    return 0;

}