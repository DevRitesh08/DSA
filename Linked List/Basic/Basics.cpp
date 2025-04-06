#include<bits/stdc++.h>
using namespace std;


// // struct Node{ // no need to use public access specifier as default is public .

// //     int data; // data of the node
// //     Node* next; // pointer to the next node

// //     // Constructor ==> special method that is automatically called when an object is created , useful for assigining initial values to its attributes .
// //                         // Key Points:
// //                             // Automatic Execution: The constructor is called right when an object is created .
// //                             // Initialization: It sets up the object's initial state, like assigning starting values to attributes.

    
// //     // Node(int data1 , Node* next1)
// //     // {
// //     //     data = data1; // initialize the data of the node
// //     //     next = next1; // initialize the pointer to the next node
// //     // }

// //     // can also do like this 
// //     Node(int data , Node* next)
// //     {
// //         this->data = data;
// //         this->next = next;
// //     }



// //     // Alternate constructor
// //     // Node(int data1 )
// //     // {
// //     //     data = data1; 
// //     //     next = nullptr; 
// //     // }

// // };   // Must


// // But we should use class to use OOP features :

//  class Node{ 

//     public: 
//             int data; // data of the node
//             Node* next; // pointer to the next node
//             // Constructor ==> special method that is automatically called when an object is created , useful for assigining initial values to its attributes .
//                                 // Key Points:
//                                     // Automatic Execution: The constructor is called right when an object is created .
//                                     // Initialization: It sets up the object's initial state, like assigning starting values to attributes.
                                
                                
//             Node(int data1 , Node* next1)    
//             {
//                 data = data1; // initialize the data of the node
//                 next = next1; // initialize the pointer to the next node
//             }
    
//             // can also do like this 
//             // Node(int data , Node* next)
//             // {
//             //     this->data = data;
//             //     this->next = next;
//             // }

            
//             // Alternate constructor ( To build a linked list, you need to explicitly set the next pointer of each node to link it to the subsequent node , shown below this code )
//             // Node(int data1 )
//             // {
//             //     data = data1; 
//             //     next = nullptr; 
//             // }
    


// };   // Must



// Basic code below

// int  main()
// {
//     vector <int> arr = {2,5,7,9};
//     Node* y = new Node(arr[0] , nullptr);
//     cout<< y << endl;   // to print the address of node 
//     cout<< y->data <<endl;

//     // but iff
//     // Node y = Node(arr[0] , nullptr);
//     // cout<<y; 
//     // throws an error because now it is an object now , not a pointer so Access members using the dot operator . 
//     // cout<<y.data; // this will work now and provide the data of the node .
//     // cout<<y.next; //prints the nullptr

// }


// complete ( USE THIS )

class Node {

    public:
            int data ;
            Node* next;
}



// // Alternate constructor wala 
// class Node {
// public:
//     int data;
//     Node* next;

//     // Constructor
//     Node(int data1) : data(data1), next(nullptr) {}
// };

// int main() {
//     // Create individual nodes
//     Node* first = new Node(2);
//     Node* second = new Node(5);
//     Node* third = new Node(7);
//     Node* fourth = new Node(9);

//     // Link the nodes
//     first->next = second;
//     second->next = third;
//     third->next = fourth;

//     // Traverse and print the linked list
//     Node* temp = first;
//     while (temp != nullptr) {
//         std::cout << temp->data << " ";
//         temp = temp->next;
//     }
//     // Output: 2 5 7 9

//     // Free the allocated memory
//     temp = first;
//     while (temp != nullptr) {
//         Node* nextNode = temp->next;
//         delete temp;
//         temp = nextNode;
//     }

//     return 0;
// }
