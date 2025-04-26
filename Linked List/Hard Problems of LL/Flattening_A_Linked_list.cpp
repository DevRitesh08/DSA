#include<bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) :
                    data(x), next(nextNode), child(childNode) {}
};

// Function to convert a vector to a linked list
Node* convertArrToLinkedList(vector<int>& arr)
{
    // Create a dummy node to serve as
    // the head of the linked list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++)
    {
        // Create a new node
        // with the vector element
        temp->child = new Node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->child; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->child; 
}

void printLinkedList(Node* head) {
   while (head) {
       cout << head->data << " ";
       head = head->next;      // ← traverse next
   }
   cout << "\n";
}

// Print the linked list
// in a grid-like structure
void printOriginalLinkedList(Node* head, int depth) 
{
   while (head != nullptr) {
       cout << head->data;

       // If child exists, recursively
       // print it with indentation
       if (head->child) 
       {
           cout << " -> ";
           printOriginalLinkedList(head->child, depth + 1);
       }

       // Add vertical bars
       // for each level in the grid
       if (head->next) 
       {
           cout << endl;
           for (int i = 0; i < depth; ++i) 
           {
               cout << "| ";
           }
       }
       head = head->next;
   }
}


// optimal Solution : (using recursion) 

Node* flatten(Node* head) 
{
    if(head == nullptr)      return head ;
    Node* temp = head ;
    while(temp != NULL)
    {
     // if the node has a child
     if(temp -> child != nullptr )
     {
         // connecting the node to its child nodes in flattened format .
         Node* nextNode = temp -> next ;
         temp -> next = flatten(temp -> child) ;
         temp -> child = nullptr ;
         // finding the tail of child nodes present below temp node .
         while(temp -> next != nullptr)
         {
             temp = temp -> next ;
         }
         // connecting the flattened child nodes to upcoming nodes .
         if(nextNode != nullptr)
         {
             temp -> next = nextNode ;

         }
     
     }
     //if there is no childs of a node .
     temp = temp -> next ; 
    }

    return head ;
}

// Time complexity is O(N) , where N is the number of nodes in the linked list.
// Space complexity is O(N) , for the recursion stack space. 

int main() {
    // Create a linked list with child pointers
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node* flattened = flatten(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
                                
                            