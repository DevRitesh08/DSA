#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[] = {1,2,3} ;
    // cout<<arr<<endl ;   // constant pointers so it will print a memory address .
    
    //  But for ,
    
    //  char str[] = {'h','e','l','l','o','\0'} ;   // not a valid string till we end it with null character(\0) , its ascii value is 0 and it also occupy the same space as the rest .
    //  cout<<str[]; // error: expected primary-expression before ']' token .
    //  cout<<str ;  // prints hello .
    //  cout<<str[1] ;  // prints e .
    //  cout<<strlen(str)<<endl ;   // prints the length of the string excluding null character (\0) .
    
    // char str[] = "hello" ;
    // cout<<str;  // this will also prints hello but as it is a character array its default working is just like above at last it contains a null poointer and all the letters of the word are stored in the form of characyters like above .

    // char str[100] ;
    // cout<<"enter a character or string to store : ";
    // cin>>str ;
    // cout<<"the output is : "<<str;
    // but if the string is entered with spaces then only the words before the first space encountered will be visible , bcoz cin is not suitable to enter strings it can only take inputs of first word .
    // so , cin.getline is used to enter string .
    // cin.getline(str,100);
    // cout<<"the output is : "<<str<<endl;

    // but just use strings data type that is already defined in the cpp stl .

    string st = "hello guys how are you !!" ;   // they are dynamic in nature , as it resizes during run time ,.
    // cout<<st<<endl ;
    string st1 = "this " ;
    string st2 = "is" ;
    string st3 = " starting of strings "; 
    string st4 =  st1 + st2 + st3 ; // concatination .
    cout<<st4<<endl ;
    cout<<(st1 == st2)<<endl ;// can also use relatonal operators they will compare strings based on lexicographical order .
    cout<<st3.length()<<endl;// giveslength of the string .

    string ST ;
    cout<<"enter string : ";
    // cin>>ST ;   // same issue use getline .
    getline(cin , ST) ;
    cout<<"the output of string ST is : "<<ST<<endl;

    for(int i = 0 ; i < st.length();i++)
    {
        cout<<st[i]<<endl;
    }

    // or using for each loop 
    for(char ch : st)   cout<<ch<<endl ;

    return 0 ;
}