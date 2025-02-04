#include <bits/stdc++.h> // compilation of various libraries in one
using namespace std;

void explainPairs();
void explainVectors();
void explainList();
void explainSet() ;
void explainMap() ;

int main() {
    //int a;
    //cout << "Enter value of a: ";
    //cin >> a;
    //cout << "Value of a is: " << a << endl;
    //explainPairs();
    explainVectors();
    //explainList();  
    //void explainSet() ;
    //void explainMap();

    // // If using namespace std; is not used then
    // std::cout << "Enter value of a: ";
    // std::cin >> a;
    // std::cout << "Value of a is: " << a << endl;
}





// void explainPairs() {
//     // First pair
//     pair<int, int> p1;
//     cout << "Enter two integers for pair p1: ";
//     cin >> p1.first >> p1.second; // Taking input for the pair
//     cout << "p1: " << p1.first << " " << p1.second << endl;
//     // Nested pair
//     pair<int, pair<int, int>> p2;
//     cout << "Enter an integer for p2.first: ";
//     cin >> p2.first; // Taking input for the first element of p2
//     cout << "Enter two integers for the nested pair in p2: ";
//     cin >> p2.second.first >> p2.second.second; // Taking input for the nested pair
//     cout << "p2: " << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
// }




// // Vectors
// // its just like the array but it stores elements dynamically , hence its size can be modified .
// void explainVectors()
// {
//     vector<int> vec;
//
//     // Adding elements to the vector
//     vec.push_back(1);// it adds an element at the last of a vector
//     vec.emplace_back(2);// it also do the same work as push_back but its way faster in doing this .
//     vec.push_back(3);
//     vec.push_back(4);
//     vec.push_back(5);
//     vec.push_back(6);
//     vec.push_back(7);
//
//     // Vector of pairs
//     vector<pair<int , int>> vec1 ;
//     vec1.push_back({5,6}) ;// for push_back {} is necessary in the () . 
//     vec1.emplace_back(5,6) ;// for emplace_back {} are not needed .
//
//     // Creating vectors with initial values
//     vector<int> v(5,100); // here 5 is size of vector v and at these locations 100 is stored . 
//     vector<int> v1(5) ; // here size is 5 but the locations are filled with 0 or any garbage value depending upon the compiler .
//     vector<int> v2(5,20) ;
//     vector<int> v3(v2);// here we are copying(so , both are not same and changes made further in them will not be visible in the other ) the elements of v2 in v3 vector .
//     // even after these size declarations we can modify their size using push_back() or emplace_back() and many other such functions .
//
//
//
//     // We can access elements of the vector in the similar way as in array using the indices , or by using iterators .
//  
//     cout<<vec[0]<<"  "<<vec[1]<<endl;
//
//     vector<int>::iterator it = v.begin(); // v.begin() points directly to the memory address of element one of vector v .  
//
//     it++; // this shifted the iterator to the memory of second element of vector v.
//     cout<<"element of vector v : " <<*(it) <<endl;// * is used to point to the value at the address that is stored in the begin() .
//
//     vector<int> ::iterator it1 = vec.end(); // // v.end() points directly to the memory address of element that is right after the last element of vector v .
//     // when it++ ; is used with v.end() then it moves to the last element of v ,if it++ used again then it points to the second last element of v
//     // for easy understanding assume it as an reverse begin just start is one less than it .
//
//     cout<<"element at last of vec : "<< vec.back()<<" "<<endl;
//
//
//     // vector printing
//     // using loop for all indices
//
//     // method 1
//     // for(vector<int>::iterator it = vec.begin() ; it != vec.end() ; it++)
//     // {
//     //     cout<<*(it)<<"  ";
//     // }
//
//     // method 2
//     // for(auto it = vec.begin() ; it != vec.end() ; it++)// vector<int>::iterator --> auto , auto will automatically assign data type based on the data it contains , works with all data types .
//     // {
//     //     cout<<*(it)<<"  ";
//     // }
//
//     // method 3
//     for(auto it : vec)// vector<int>::iterator --> auto , auto will automatically assign data type based on the data it contains , works with all data types .
//     {
//         cout<<it<<"  ";
//     }
//     cout<<endl;
//
//
//
//     // deletion of elements from an vector
//     // vec = {1,2,3,4,5,6,7}
//
//     // //method 1
//     // vec.erase(vec.begin()+1); // element --> 2
//
//     //method 2
//     vec.erase(vec.begin() + 2 , vec.begin() + 4 ); // vec.begin() + 4 --> end address , it should be one more than upto which deletion is to be done . so start is included and end is excluded .
//
//     cout<<"vector after deletion : "<<endl;
//     for(auto it : vec)// vector<int>::iterator --> auto , auto will automatically assign data type based on the data it contains , works with all data types .
//     {
//         cout<<it<<"  ";
//     }
//
//
//
//     // insert function (takes much more time)
//     vector<int>Ve(2,100); // {100,100}
//     Ve.insert(Ve.begin(),300); // {300,100,100}
//     Ve.insert(Ve.begin() + 1 , 2 , 7); // {300,7,7,100,100}
//
//     vector<int> copy(2,50); // {50,50}
//     Ve.insert( Ve.begin() , copy.begin() , copy.end() ); // {50,50,300,10,10,100,100}
//
//     //{10,20}
//     cout<<Ve.size(); // 2
//
//     //{10,20}
//     Ve.pop_back(); // {10}
//
//     //swap
//     vector<int> r = {1,2,3};
//     vector<int> rs = {0,9,8};
//     r.swap(rs); // r --> {0,9,8} and rs --> {1,2,3}
//     cout<<endl<<"swap : ";
//     for(auto it : r)
//     {
//         cout<<it<<"  ";
//     }
//     cout<<endl;
//
//
//     // Clear the contents of vector r
//     r.clear(); // Erases all elements in r
//     cout << "After clear, size of r: " << r.size() << endl; // Should print 0
//     cout<<"empty : "<<r.empty();//should print 1 that means true
//
//
// }





// //LIST
// // it is similar to vector , doubly linked list is maintained for list , whereas for vector singly linked list is maintained .
// void explainList()
// {
//     list<int> ls;

//     ls.push_back(2); // {2}
//     ls.push_back(3); // {2,3}
//     ls.push_back(4); // {2,3,4}
//     ls.push_back(5); // {2,3,4,5}
//     ls.push_front(1); // {1,2,3,4,5} , it takes less time then insert of vector
//     ls.emplace_front(0); // {0,1,2,3,4,5}

//     // redt functions are same as vectors 
//     // like swap, end , clear , insert ,size

// }





// // DEQUE
// void explainDeque()
// {
//     deque<int> dq ;
//     dq.push_back(1); // {1}
//     dq.emplace_back(3); // {1,3}
//     dq.push_front(9); // {9,1,3}
//     dq.emplace_front(6); // {6,9,1,3}

//     dq.pop_back(); // {6,9,1}
//     dq.pop_front(); // {9,1}

//     dq.back(); //
//     dq.front(); //

//     // rest functions are same as vector
//     //end , clear , insert , size , swap
// }





// //STACK ( lifo --> last in first out )
// void explainStack()
// {
//     stack<int> st; 
//     st.push(1);// {1}
//     st.push(2);// {2,1}
//     st.push(3);// {3,2,1}
//     st.push(3);// {3,3,2,1}
//     st.emplace(5);// {5,3,3,2,1}

//     cout<<st.top(); // prints 5 "st[2] is invalid ", as we cant access elements using indices in stack .

//     st.pop();// {3,3,2,1}

//     cout<< st.top();// 3

//     cout<<st.size();// 4

//     cout<< st.empty(); // 1 

//     stack<int> st1,st2 ;
//     st1.swap(st2);

// }





// // QUEUE ( fifo --> first in first out )
// void explainQueue()
// {
//     queue <int> q;
//     q.push(1) ; // {1}
//     q.push(2) ; // {1,2}
//     q.emplace(4) ; // {1,2,4}

//     q.back() += 5 ; // {1,2,9}

//     cout<<q.front(); // prints 1
    
//     q.pop();// {2,9}

//     cout << q.front(); // prints 2

//     // size , swap , empty functions are same as stack .

// }





// // PRIORITY QUEUE
// void explainPQ()
// {
//     // stores maximum value at top (max heap)
//     priority_queue<int>pq ;
    
//     pq.push(5); // {5}
//     pq.push(2); // {5,2}
//     pq.push(8); // {5,2,8}
//     pq.emplace(10); // {10,8,5,2}

//     cout << pq.top(); // prints 10

//     pq.pop(); // {8,5,2}

//     cout << pq.top(); // prints 8

//     // size , swap and empty functions are same as others

//     // minimum heap (min heap)
//     // stores minimum value at top
//     priority_queue< int , vector<int> , greater<int> > pq2 ;
//     pq2.push(5);// {5}
//     pq2.push(2);// {2,5}
//     pq2.push(8);// {2,5,8}
//     pq2.emplace(10);// {2,5,8,10}

//     cout << pq2.top() ; // print 2
// }

// // time complexity
// // push() --> O(log n)
// // pop() --> O(log n)
// // top() --> O(1)





// // SET
// // it stores elements in sorted order (ascending) and stores only unique elements .
// void explainSet()
// {
//     set<int> st ;
//     st.insert(1);// {1}
//     st.emplace(2);// {1,2}
//     st.insert(2);// {1,2}
//     st.insert(4);// {1,2,4}
//     st.insert(3);// {1,2,3,4}

//     // functionality of insert in vector can also be used , 
//     // that only increases efficiency

//     // begin(),end(),size(),empty() and swap() are same as those of above .

//     // st = {1,2,3,4}
//     auto it = st.find(3);
//     st.erase(it); // it takes constant time

//     st.erase(5); // erases 5 , takes logarithmic size

//     // {1,2,3,4}
//     auto it1 = st.find(2);
//     auto it2 = st.find(4);
//     st.erase( it1 , it2 ); //{1,4} {first , last}

//     // lower_bound() and upper_bound() functions works in the same way , as in vector it does .

//     //syntax
//     auto it = st.lower_bound(2);
//     auto it = st.upper_bound(3);

// }





// // MULTI-SET
// // it stores elements in sorted order (ascending) and also stores duplicate elements .
// // MULTI-SET
// // It stores elements in sorted order (ascending) and allows duplicate elements.
// void explainMultiSet() {
//     // Everything is the same as Set, but it can also store duplicate elements.
    
//     multiset<int> ms;
//     ms.insert(1); // {1}
//     ms.insert(1); // {1, 1}
//     ms.insert(1); // {1, 1, 1}

//     // Erases all occurrences of 1
//     ms.erase(1); // All 1's erased

//     // Reinserting elements to demonstrate other operations
//     ms.insert(1); // {1}
//     ms.insert(2); // {1, 2}
//     ms.insert(2); // {1, 2, 2}
//     ms.insert(3); // {1, 2, 2, 3}

//     // Counts the number of occurrences of 1 in the multiset
//     int cnt = ms.count(1); // Counts number of 1's in the multi-set

//     // To erase a single instance of 1 (if it exists)
//     if (ms.find(1) != ms.end()) {
//         ms.erase(ms.find(1)); // Erases only one occurrence of 1
//     }

//     // Using iterators to erase a range of elements
//     auto it1 = ms.find(2); // Iterator to the first occurrence of 2
//     if (it1 != ms.end()) {
//         auto it2 = it1;
//         advance(it2, 2); // Advances the iterator by 2 positions
//         ms.erase(it1, it2); // Erases elements from 'it1' to 'it2' (exclusive)
//     }

//     // Rest of the functions are the same as Set
// }






// // UNORDERED SET
// //it is same as set but it does not store elements in sorted order
// void explainUnorderedSet()
// {
//     unordered_set<int> st ;
//     // lower_bound and upper_bound functions does not work , rest all
//     // functions are same as above , it does not stores in any particular 
//     // order it has a better complexity then set in most cases , except some when 
//     // collision happens .
// }





// // MAP
// // map stores unique keys in sorted order .
// // combination of key and value where key  is always unique and value can be duplicate .
// // key and value can be of any data type
// void explainMap() {
//     // {key, value}: first is always the key and second is the value
//     map<int /* key */, int /* value */> mpp1;

//     // Map with value as a pair
//     map<int /* key */, pair<int, int> /* value */> mpp2;

//     // Map with a pair as the key
//     map<pair<int, int> /* key */, int /* value */> mpp3;

//     // Working with mpp1
//     mpp1[1] = 2;             // {1, 2}
//     mpp1.emplace(3, 1);      // {3, 1}
//     mpp1.insert({2, 4});     // {2, 4}

//     // Working with mpp3
//     mpp3[{2, 3}] = 10;       // {{2, 3}, 10} where {2, 3} is the key and 10 is the value

//     // Iterating over mpp1
//     for (auto it : mpp1) {
//         cout << it.first << " " << it.second << endl;
//     }

//     // Accessing elements in mpp1
//     cout << mpp1[1] << endl; // Output the value associated with key 1
//     cout << mpp1[5] << endl; // Outputs 0 (default value), as key 5 is not present

//     // Corrected syntax for find
//     auto it = mpp1.find(3); // Using parentheses for find
//     if (it != mpp1.end()) {
//         cout << it->second << endl; // Output the value associated with key 3
//     }

//     // Another example of find
//     auto it2 = mpp1.find(5); // If key 5 is not present, it2 will be mpp1.end()

//     // Syntax for lower_bound and upper_bound
//     auto it3 = mpp1.lower_bound(2); // Returns iterator to the first key >= 2
//     auto it4 = mpp1.upper_bound(3); // Returns iterator to the first key > 3

//     // erase, swap, size, and empty functions are the same as in other containers
// }





// // MULTI-MAP
// void explainMultiMap()
// {
//     // everything is same as map , only it can store duplicate keys
//     // and mpp[key] cannot be used here .
// }





// // UNORDERED MAP
// // store unique keys and store in random order.
// void explainUnorderedMap()
// {
//     // same as set and unordered_set difference .
// }











// // Comparison function for custom sorting
// bool comp(pair<int, int> p1, pair<int, int> p2) {
//     if (p1.second < p2.second) return true;
//     if (p1.second > p2.second) return false;

//     // If the second elements are the same, sort by the first element in descending order
//     if (p1.first > p2.first) return true;
//     return false;
// }

// void explainExtra() {
//     // Standard sorting functions

//     // Sorting an array a[] from a to a+n in ascending order
//     sort(a, a + n);

//     // Sorting a vector v in ascending order
//     sort(v.begin(), v.end());

//     // Sorting a subarray from a[2] to a[3] (inclusive)
//     sort(a + 2, a + 4);

//     // Sorting an array a[] in descending order using greater<int>
//     sort(a, a + n, greater<int>());

//     // Example of sorting pairs
//     pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

//     // Sort the array of pairs using the custom comparator `comp`
//     // Sorting rules:
//     // 1. Sort by the second element in ascending order
//     // 2. If the second elements are the same, sort by the first element in descending order
//     sort(a, a + n, comp);

//     // Result after sorting: {4, 1}, {2, 1}, {1, 2}

//     // Counting set bits (number of 1s) in the binary representation of an integer
//     int num = 7;
//     int cnt = __builtin_popcount(num); // For a 32-bit integer

//     // Counting set bits for a long long integer
//     long long large_num = 234354665432312;
//     int cnt_ll = __builtin_popcountll(large_num); // For a 64-bit integer

//     // Generating all permutations of a string
//     string s = "123";
//     sort(s.begin(), s.end()); // Sort the string to start with the smallest permutation

//     // Using next_permutation to generate all permutations
//     do {
//         cout << s << endl;
//     } while (next_permutation(s.begin(), s.end()));

//     // Finding the maximum element in an array
//     int maxi = *max_element(a, a + n);
// }

 