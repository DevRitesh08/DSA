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



// Brute Solution ( Hashing )

// bool detectLoop(Node* head) 
// {
//     Node* temp = head;  
    
//     // unordered map is used to keep track of
//     // encountered nodes
//     unordered_map<Node*, int> nodeMap;  
//     // Note: Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.


//     while (temp != nullptr) // terminates the loop if there is no loop because at last it'll point to nullptr .
//     {
//         // If the node is already in the
//         // map, there is a loop
//         if (nodeMap.find(temp) != nodeMap.end()) {
//             return true;
//         }
//         // Store the current node
//         // in the map
//         nodeMap[temp] = 1;
        
//         // Move to the next node
//         temp = temp->next;  
//     }

//     // If the list is successfully traversed 
//     // without a loop, return false
//     return false;
// }

// Time Complexity: O(N * 2 * log(N) )The algorithm traverses the linked list once, performing hashmap insertions and searches in the while loop for each node. The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time complexity is determined by the product of the traversal (O(N)) and the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 

// Space Complexity: O(N) The code uses a hashmap/dictionary to store encountered nodes, which can take up to O(N) additional space, where 'n' is the number of nodes in the list. Hence, the spacecomplexity is O(N) due to the use of the map to track nodes .




// Optimal Approach (Tortoise and Hare algorithm)

bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next; 

        if(fast == slow )   return true;
    }

    return false ;
}
 
// Time Complexity: O(N), where N is the number of nodes in the linked list. This is because in the worst-case scenario, the fast pointer, which moves quicker, will either reach the end of the list (in case of no loop) or meet the slow pointer (in case of a loop) in a linear time relative to the length of the list.

// The key insight into why this is O(N) and not something slower is that each step of the algorithm reduces the distance between the fast and slow pointers (when they are in the loop) by one. Therefore, the maximum number of steps needed for them to meet is proportional to the number of nodes in the list.

// space complexity is O(1) .

int main() 
{
    // Create a sample linked list
    // with a loop for testing
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (detectLoop(head)) 
    {
        cout << "Loop detected in the linked list." << endl;
    } 
    else 
    {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}


