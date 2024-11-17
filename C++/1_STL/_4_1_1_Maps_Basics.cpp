// for in-built implementation it uses trees .

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    // Map is a data structure which stores key(Unique) and value pairs , <key , value> .
    // the values in a map are stored in sorted order according to the key values , and the keys stored will always be unique if same key entered twice then the value of second key replaces the first value of that key in the map .
    // elements in map are not stored in continous memory location , they are linkes between them so it + 1 can't be used , use only it++ .





    // Declaration
    map<int , string> m; // int is the data type for key , string is the data type for value .





    // initialization 
    
    // // method 1
    m[1] = "how"; // time complexity of single is O(logN)
    // m[7] ; // when value is not given when too time complexity will be O(logN) and the value for string will be an empty string and for int,float,double.... it will be zero .
    m[2] = "are";
    m[3] = "you";
    m[4] = "good";
    m[4] = "not good"; // it will replace good by not good as the keys are same .

    // // method 2
    // m.insert({6,"good"});
    // m.insert({5,"am"});
    // m.insert({4,"i"});





    // map printing (also proof that it is stored in sorted order because of output)

    // if the data type of key is string then sorting will be done like dictionary .


    //m-1
    // for(auto it = m.begin() ; it != m.end() ; it++)
    // {
    //     cout<<(*it).first << " "<< (*it).second<<endl;
    // }
    //m-2
    // for(auto &x : m ) // TIME COMPLEXITY IS O(NlogN) --> logN for each single print same as input so for all inputs too TIME COMPLEXITY will be O(NlogN) .
    //  {
    //     cout<<x.first << " "<< x.second<<endl;
    // }





    // finding element in a map
    auto it = m.find(3) ; // TIME COMPLEXITY IS O(logN) .
    // it will return the iterator of the key = 3 if it's present if not present then it will return ( m.end() )th iterator which is the iterator of the  next element after the end element .
    // if(it == m.end() )
    // {
    //     cout<<" no value";
    // }
    // else 
    // {
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }




    // Erasing element in a map
    // m.erase();  it erases the the element , its TIME COMPLEXITY is O(logN) , N is size of map .
    // it can have both inputs key and iterator
    // by key
    // m.erase(1); // 
    // m.erase(it); // it = 3 from find part so also erased
    // for(auto &x : m ) 
    //  {
    //     cout<<x.first << " "<< x.second<<endl;
    // }
    
    
    // but if an iterator which is not the part of the map ( m.end() ) is used then it will result in a segmentation fault .
    it = m.find(7);
   // m.erase(it);
    // so use a check  
    if(it != m.end() )
        m.erase(it);
    
    //m.erase(); it can't delete the whole map to do so we can use m.clear() it also works in other cases of erase too .
    m.clear();
    for(auto &x : m ) 
     {
        cout<<x.first << " "<< x.second<<endl;
    }



    // TIME COMPLEXITY of insertion is not always O(logN) it also depends on the key as there is also comparisons inside the key's so when map has int then it has time complexity of O(logN) , but if key is a string then it will also compare it with other strings ( to sort ) of key so, TIME COMPLEXITY will be O( str.size()*log(N) ) ---> O( s*log(N) ) , s is size of string and N is size of map . 


    


}