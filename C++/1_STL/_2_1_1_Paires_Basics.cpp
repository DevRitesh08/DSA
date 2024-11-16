#include<bits/stdc++.h>
using namespace std;

int main ()
{
    pair<int , string> p1 ; // pair can be of  data types , containers or both at the same time .



    // initialization of pair
    
    // method 1
    //p1 =  make_pair(2 , "ritesh");

    // method 2
    p1 = {2 , "ritesh"};



    // pair printing

    //cout<<p1.first<<endl<<p1.second;



    // pair values input from the user

    // cin>>p1.first>>p1.second;
    // cout<<"first value of p1 : "<<p1.first<<endl<<"second value of p1 : "<<p1 .second<<endl ;


    // copying a pair

    // // method 1 ( call by value)
    // pair<int , string> p2 = p1 ;
    // p2.second = "swami" ;
    // cout<<p1.first<<" "<<p1.second<<endl;
    // cout<<p2.first<<" "<<p2.second<<endl;

    // // method 2 ( call by reference)
    // pair<int , string> &p2 = p1 ;
    // p2.second = "swami" ;
    // cout<<p1.first<<" "<<p1.second<<endl;
    // cout<<p2.first<<" "<<p2.second<<endl;



    // application of pairs --> tracking of changes in pair elements ( maintains relation between the pair elements )

    int a[] = {1,2,3};
    int b[] = {0,9,8};
    // if any changes is done in array a then how can we track the changes the answer to this is pairs , in order to do so we can make an pair array .
    pair<int , int > p_array[3];
    p_array[0] = {1,0};
    p_array[1] = {2,9};
    p_array[2] = {3,8}; 

    swap(p_array[0] , p_array[2]) ;
    // printing of pair array
    for(int i = 0 ; i < 3 ; i++)
    {
        cout<< p_array[i].first <<" "<<p_array[i].second<<endl;
    }


}