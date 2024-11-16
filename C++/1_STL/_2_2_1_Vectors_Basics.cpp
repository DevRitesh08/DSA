#include<bits/stdc++.h>
using namespace std ;

// vector also have same limits as arrays :
// when vector is declared inside the main function then it can have a maximum size of 10^6 .
// when vector is declared globally then it can have a maximum size of 10^7 .
// these limits are not on arrays or vectors , these are on continous memory allocations .


// vector is just like the array but with dynamic size , so unlike array it does not occupy any space at the time of declaration .

// just like arrays vectors also stores elements at contiguous memory locations .


void PrintVector(vector<int> v ) // HERE VECTOR IS PASSED BY CALL BY VALUE , so changes made here will not ne reflected in the vector in main function , TIME COMPLEXITY of this is O(N) , to pass the vector by refrence just do
// void PrintVector(vector<int> &v ) 
// now , changes made inside this function will also be displayed in the main function , and its TIME COMPLEXITY WILL BE O(1).
{

    // time complexity of size() function is O(1).
    // v.size() gives the size of a vector 

    cout<<"the size of vector is : "<<v.size()<<endl;

    //PrintVector(vec1);
    for(int i = 0 ; i < v.size() ; i++)
        cout<< v[i] << " ";

    cout<<endl;

}



void PrintString(vector<string> v)
{
     cout<<"the size of vector is : "<<v.size()<<endl;

    for(int i = 0 ; i < v.size() ; i++)
        cout<< v[i] << " ";

    cout<<endl;
}


int main ()
{
    // vector can be of any data type int , double , string , containers and  pairs .





    // Declaration of vector

    vector<int> vec1 ; // currently the memory occupied by the vector is zero .
    

    
    // value insertion in an vector 

    // int n ;
    // cout<<"Enter the size of vactor : ";
    // cin>>n ;
    // for(int i = 0 ; i < n ; i++) // total time comlexity including the for loop will be O(N)
    // {
    //     int x ; 
    //     cin >> x ;
    //     vec1.push_back(x) ; // it pushes the value to the end of the vector .

    //     // time complexity of push_back function is similar to that of a array insertion in an array --> O(1)

    //     // proof that vectors have dynamic size 
    //     PrintVector(vec1) ;

    // }





    //vector can also be declared manually


    // // method 1 : 

    // vector<int> vec2(10) ; // it will initalize the all the values of the vec2 by default by zero .
    // PrintVector(vec2);

    // // size of vector can still be increased (dynamically)
    // vec2.push_back(22);
    // PrintVector(vec2);

    // // size of vector can also be decreased (dynamically)
    // vec2.pop_back(); // removes the last element from the vector

    // time complexity of pop_back() function is also O(1) like push_back() .

    // vec2.pop_back();
    // PrintVector(vec2);

    // method 2 : 

    // ways to pre-fill array :  
    vector<int> vec3(10,5); // all the 10 values will be initialized to 5 .
    // PrintVector(vec3); 





    // copying a vector

    // this also copies the vector element by element just like arrays so its TIME COMPLEXITY is also O(N) .
    vector<int> vec4 = vec3 ; // here vec4 is copy of vec3 and changes made in vec3 after this will not be reflected in vec4 ..
    // we can also pass the reference of vec3 in vec4 by doing 
    // vector<int> &vec4 = vec3 ;
    // its TIME COMPLEXITY will be O(1) .

    // vec3.pop_back();
    // PrintVector(vec3);  
    // PrintVector(vec4);





    // string vector 

    vector<string> vec5 ;
    int p ;
    cout<<"enter number of strings to store in vector : ";
    cin>>p ;
    for(int i = 0 ; i < p ; i++)
    {
        string str ;
        cin >> str ;
        vec5.push_back(str) ;
    }

    //PrintString(vec5) ;





}