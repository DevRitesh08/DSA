#include<bits/stdc++.h>
using namespace std;

struct Node{ // no need to use public access specifier as default is public .

    int data; // data of the node
    Node* next; // pointer to the next node

    // Constructor ==> special method that is automatically called when an object is created , useful for assigining initial values to its attributes .
                        // Key Points:
                            // Automatic Execution: The constructor is called right when an object is created .
                            // Initialization: It sets up the object's initial state, like assigning starting values to attributes.

    
    // Node(int data1 , Node* next1)
    // {
    //     data = data1; // initialize the data of the node
    //     next = next1; // initialize the pointer to the next node
    // }

    // can also do like this 
    Node(int data , Node* next)
    {
        this->data = data;
        this->next = nullptr;
    }

    

    // Alternate constructor
    // Node(int data1 )
    // {
    //     data = data1; 
    //     next = nullptr; 
    // }

};   // Must

int  main()
{
    vector <int> arr = {2,5,7,9};
    Node* y = new Node(arr[0] , nullptr);
    cout<< y << endl;   // to print the address of node 
    cout<< y->data <<endl;

    // but iff
    // Node y = Node(arr[0] , nullptr);
    // cout<<y; 
    // throws an error because now it is an object not a pointer so 
    // cout<<y.data; // this will work now and provide the data of the node .
    // cout<<y.next; //prints the nullptr


}