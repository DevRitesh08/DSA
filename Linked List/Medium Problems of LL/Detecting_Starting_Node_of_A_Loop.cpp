#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;       
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};



// Brute Solution (Hashing)

// Node* detectLoop(Node* head) 
// {
//     Node* temp = head;
//     unordered_map<Node*, int> mp;

//     while(temp!=NULL)
//     {
//         // check if temp has been encountered again
//         if(mp.count(temp)!=0)
//         {
//             // A loop is detected hence return temp
//             return temp;
//         }
//         // store temp as visited
//         mp[temp] = 1;
//         // iterate through the list
//         temp = temp->next;
//     }

//     // If no loop is detected, return nullptr
//     return nullptr; 
// }

// Time complexity is O(N) , since the tc of find , count insertion in best and average case is O(1) , and in extremely rare case it is O(N) .
// Space complexity is O(N) .



// Optimal solution (Tortoise and hare algorithm )

Node* detectLoop(Node* head) 
{
    
    // Initialize a slow and fast 
    // pointers to the head of the list
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) 
    {
        
        // Move slow one step
        slow = slow->next;        
        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast) 
        {
            
             // Reset the slow pointer
             // to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) 
            {
                
                // Move slow and fast one step
                // at a time
                slow = slow->next;  
                fast = fast->next;  

                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  // or fast ;
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}
        
// Time complexity is O(N) , since we are traversing every node .




int main() 
{
    // Create a sample linked list with a loop
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = detectLoop(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}
                                
                            