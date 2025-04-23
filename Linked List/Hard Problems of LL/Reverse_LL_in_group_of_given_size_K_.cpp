#include<bits/stdc++.h>
using namespace std ;

class Node 
{
    public:
        int data;
        Node* next;
        Node(int val) 
        {
            data = val;
            next = NULL;
        }
};


void print(Node* head)
{
    while (head != nullptr)
    {
        cout<<head->data<<"  ";
        head = head -> next; 
    }
}

Node* Arr2LL(vector <int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp ; // or mover = mover ->  next ;
    }

    return head;    // since in LL head is the key to whole LL .
}


// Problem Statement: Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.





// Brute Force :

// Function to reverse a linked list
// using the 3-pointer approach
Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at
   // head of linked list
   Node* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   Node* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL)
   {  
       // Store the next node in
       // 'front' to preserve the reference
       Node* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

// Function to get the Kth node from
// a given position in the linked list
Node* getKthNode(Node* temp, int k)
{
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 

    // Decrement K until it reaches
    // the desired position
    while(temp != NULL && k > 0)
    {
        // Decrement k as temp progresses
        k--; 
        
        // Move to the next node
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
}

// Function to reverse nodes in groups of K
Node* kReverse(Node* head, int k)
{
    // Initialize a temporary
    // node to traverse the list
    Node* temp = head; 

    // Initialize a pointer to track the
    // ;ast node of the previous group
    Node* prevLast = NULL; 
    
    // Traverse through the linked list
    while(temp != NULL)
    {
        // Get the Kth node of the current group
        Node* kThNode = getKthNode(temp, k); 

        // If the Kth node is NULL
        // (not a complete group)
        if(kThNode == NULL)
        {
            // If there was a previous group,
            // link the last node to the current node
            if(prevLast)
            {
                prevLast -> next = temp; 
            }
            
            // Exit the loop
            break; 
        }
        
        // Store the next node
        // after the Kth node
        Node* nextNode = kThNode -> next; 

        // Disconnect the Kth node
        // to prepare for reversal
        kThNode -> next = NULL; 

        // Reverse the nodes from
        // temp to the Kth node
        reverseLinkedList(temp); 
        
        // Adjust the head if the reversal
        // starts from the head
        if(temp == head)
        {
            head = kThNode;
        }
        else
        {
            // Link the last node of the previous
            // group to the reversed group
            prevLast -> next = kThNode; 
        }

        // Update the pointer to the
        // last node of the previous group
        prevLast = temp; 

        // Move to the next group
        temp = nextNode; 
    }
    
    // Return the head of the
    // modified linked list
    return head; 
}



// using recursion :


ListNode* reverseKGroup(ListNode* head, int k) {
    // Count total nodes in the current segment
    ListNode* temp = head;
    int count = 0;
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    // If there are at least k nodes, proceed to reverse
    if (count == k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int c = 0;

        while (curr != nullptr && c < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }

        // Recurse on the remaining list
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // prev is the new head of this reversed group
        return prev;
    }

    // If fewer than k nodes left, return head as-is
    return head;
}


int main()
{
    vector <int> arr = {1,2,3,4,5,6,7,8,9} ;
    Node* head = Arr2LL(arr);
    head = LastGroupNode(head , 3);
    
    // print(head);

    return 0 ;
}