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


void printLinkedList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



// Brute Force ( using stack )

bool isPalindrome(Node* head) 
{
    // Create an empty stack
    // to store values
    stack<int> st;
    Node* temp = head;

    // Traverse the linked list and
    // push values onto the stack
    while (temp != NULL) 
    {
        
        // Push the data from the
        // current node onto the stack
        st.push(temp->data); 
        temp = temp->next;  
    }

    // Reset the temporary pointer back
    // to the head of the linked list
    temp = head;

    // Compare values by popping from the stack
    // and checking against linked list nodes
    while (temp != NULL) 
    {
        if (temp->data != st.top()) 
        {
            // If values don't match,
            // it's not a palindrome
            return false; 
        }
        
        // Pop the value from the stack
        st.pop();
        
        temp = temp->next; 
    }

     // If all values match, then it is a palindrome .
    return true;
}

// Time complexity is O(2N) .
// Space complexity is O(N) .




// Optimal Solution ( using Tortoise and hare algo + 2 pointer approch)

// function to reverse links : (Recursive)
Node* reverselinks(Node* head )
{
    if(head == nullptr || head -> next == nullptr)      return head ;       // Base Case
    Node* newhead = reverselinks(head -> next);
    Node* front = head -> next ;
    front -> next = head ;
    head -> next = nullptr ;
    return newhead ;
}
// function to check pallindrome : (Tortoise and Hare algo + 2 pointers)
Node* isPallindrome(Node* head)
{
    if(head == nullptr || head -> next == nullptr)      return true ;
    Node* slow = head ;
    Node* fast = head ;
    while(fast -> next != nullptr && fast -> next -> next != nullptr) //condition for odd and even respectively .
    {

        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    Node* newhead = reverselinks(slow -> next );
    Node* first = head ;
    Node* second = newhead ;
    while(second != nullptr)
    {
        if(first -> data != second ->data)
        {
            reverselinks(newhead) ;     // good practise (don't alter the given data (LL) )
            return false ;
        }
        first = first -> next ;
        second = second -> next ;
    }

    reverselinks(newhead) ;     // good practise (don't alter the given data (LL) )
    return true ;
}

// Time complexity is O( N/2 + N/2 + N/2 + N/2 ) ==> O(2N)



int main() {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}


