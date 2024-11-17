// we can access elements of vector by indexing just like arrays but there are many other containers like map,set...etc that cannot be accessed directly , here iteraors are used in order to access them .
// ITERATORS are just like the pointers they point to the address of the elements of containers . 

#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> vec = {1,2,3,4,5,6};
    // vector print using indexing
    // for(int i = 0 ; i < vec.size() ; i++)
    // {
    //     cout<<vec[i]<<" ";
    // }
    // cout<<endl;
    
    // declaration of an ITERATOR
    vector<int> :: iterator it = vec.begin(); // vec.begin() --> points to the address of first element of vector vec .


    // vector printing using iterator


    // cout<<(*it)<<endl; // prints first element of vec
    // cout<<(*(it+1))<<endl;// prints second element of vec

    cout<<"Vector : ";
    for(it = vec.begin() ; it != vec.end() ;  it++) // vec.end() --> points to the address of ( last + 1 )th element .
    {
        cout<< (*it) << " ";
    }
    cout<<endl;



    // DIFFRENCE BETWEEN it++ and it + 1 .
    // it++ --> points to the next iterator
    // it + 1 --> points to the next location which in case of vector is same as next iterator as here elements are stored continously but in case of other containers like map , set ....etc they are diffrent as there elements are connected with some links they are not in continous memory locations .




    // use of iterators for pair
    vector<pair<int , int> > vec_p = {{1,2} , {2,3} , {3,4} };
    vector<pair<int,int> > :: iterator it2 ;

    // for(it2 = vec_p.begin() ; it2 != vec_p.end() ; it2++)
    // {
    //     cout<<(*it2).first<<" "<<(*it2).second<<endl;
    // }
    // another way to point using iterator 
    // for(it2 = vec_p.begin() ; it2 != vec_p.end() ; it2++)
    // {
    //     cout<<(it2->first)<<" "<<(it2->second)<<endl;
    // }

    // so , (*it2).first <----> (it2->first) 
    // both are valid !(prefer second one)


    // shortcut way to print for range based loops (works for all containers)
    // cout<<"shortcut print : ";
    // for(int value : vec) // its a copy of vector vec
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;

    // // proof
    //  for(int value : vec) 
    // {
    //     value++;
    // }
    //  for(int value : vec) 
    // {
    //     cout<<value<<" ";
    // }


    // to print values by reference in range based loops
    for(int &value : vec) // its a copy of vector vec
    {
        cout<<value<<" ";
    }

    // proof
     for(int &value : vec) 
    {
        value++;
    }
    cout<<endl;
     for(int value : vec) 
    {
        cout<<value<<" ";
    }

    // works for pairs too
    vector<pair<int , int> > v_p = {{1,2} , {2,3} , {3,4}};
    cout<<endl<<"pair print : "<<endl;
    for(pair<int,int> &value : v_p) // its a copy of vector vec
    {
        cout<<value.first<<" "<<value.second<<endl;
    }





    // auto --> it is a keyword which can automatically detects the data type of variable based on the elements stored inside them
    // it is very helpful in case of iterators as now no need to write the long initialize statement of iterator .

   // vector<int> :: iterator it = vec.begin(); // NO NEED OF THIS LINE

    cout<<"Vector print using auto keyword : ";
    for(auto it = vec.begin() ; it != vec.end() ;  it++) // vec.end() --> points to the address of ( last + 1 )th element .
    {
        cout<< (*it) << " ";
    }
    cout<<endl;
    // so do this only for pairs , containers .....etc
    
}