#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;   
    Node* next;   

    Node(int data1, Node* next1) 
    {
        data = data1;
        next = next1;
    }

    Node(int data1) 
    {
        data = data1;
        next = nullptr;
    }
};




// Brute solution (Hashing)

// int lengthOfLoop(Node* head) 
// {
//     // Hashmap to store visited
//     // nodes and their timer values
//     unordered_map<Node*, int> visitedNodes; 
//     Node* temp = head; 
    
//     // Initialize timer to track
//     // visited nodes
//     int timer = 0; 

//     while (temp != NULL) 
//     {
        
//         // If revisiting a node return
//         // the difference of timer values
//         if (visitedNodes.find(temp) != visitedNodes.end()) 
//         {
//             // Calculate the length of the loop
//             int loopLength = timer - visitedNodes[temp];
            
//             // Return the length of the loop
//             return loopLength; 
//         }
//         // Store the current node and
//         // its timer value in the hashmap
//         visitedNodes[temp] = timer;
        
//         // Move to the next node
//         temp = temp->next;
        
//          // Increment the timer
//         timer++;
//     }

//     // If traversal is completed and
//     // we reach the end of the list (null)
//     // means there is no loop
//     return 0;
// }

// Time complexity is O(N) and space complexity is also O(N) .





// Optimal Solution (Tortoise and Hare algorithm)

int lengthOfLoop(Node* head)
{
    Node* slow = head ;
    Node* fast = head ;

    while (fast != nullptr && fast -> next != nullptr)
    {
        fast = fast -> next -> next ;
        slow = slow -> next ;
        
        if(fast == slow)
        {
            int cnt = 1 ; // not 0 because of fast = fast -> next ;
            fast = fast -> next ;

           while(fast != slow )
           {
            cnt++ ;
            fast = fast -> next ;
           }

           return cnt ;
        }
    }

    return 0 ;
}



int main() 
{    
    Node* head = new Node(1);
    Node* second = new Node(2);-
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) 
    {
        cout << "Length of the loop: " << loopLength << endl;
    } 
    else 
    {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}


