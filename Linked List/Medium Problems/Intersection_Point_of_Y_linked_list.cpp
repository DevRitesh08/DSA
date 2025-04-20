#include<bits/stdc++.h>
using namespace std;

class node 
{
    public:
        int num;
        node* next;
        node(int val) 
        {
            num = val;
            next = NULL;
        }
};

//utility function to insert node at the end of the linked list
void insertNode(node* &head,int val) 
{
    node* newNode = new node(val);
    
    if(head == NULL) 
    {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void printList(node* head) 
{
    while(head->next != NULL) 
    {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}





// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.


// Brute Force :
// Concept: For each node in the first list, traverse the entire second list to check for a matching node.

node* intersectionPresent(node* head1,node* head2) 
{
    while(head2 != NULL) // list whose each value is checked .
    {
        node* temp = head1;
        while(temp != NULL) // second list to be traversed each time for matching a node .
        {
            //if both nodes are same
            if(temp == head2)       return head2 ; // or temp 
            temp = temp -> next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists 
    return NULL ;
}

// Time complexity is O(M*N) .





// Better Solution ( Hashing ) :

node* intersectionPresent(node* head1,node* head2) 
{
    unordered_set<node*> st;
   while(head1 != NULL) 
   {
      st.insert(head1);
      head1 = head1->next;
   }
   while(head2 != NULL) 
   {    // st.find(head2) it returns an iterator
       if(st.find(head2) != st.end()) return head2; // it is a special iterator that points to the past-the-end ( one position after the last valid element in a container) element .
       head2 = head2->next;
   }

   return NULL;

}





// Better solution




int main() 
{
    // creation of both lists 
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}