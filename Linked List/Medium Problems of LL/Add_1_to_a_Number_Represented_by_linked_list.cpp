#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
            int data;
            Node* next ;
            // constructor
            Node(int data1)
            {
                data = data1 ;
                next = nullptr ;
            }

            Node(int data1 , Node* next1)
            {
                data = data1 ;
                next = next1 ;
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

Node* Arr2DLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = mover -> next ; // or prev = prev ->  next ;
    }

    return head;    // since in LL head is the key to whole LL .
}

Node* reverse(Node* head)
{
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr)
    {
        Node* front = temp -> next ; // important to store it as the link will be broken in next line .
        temp -> next  = prev ;
        prev = temp ;
        temp = front ;
    }
    return prev ; // as it will be the new head of linked list , since temp will point to nullptr .
}




// Brute Solution :

// Node* add_1_LL(Node* head)
// {
//     head = reverse(head) ;
//     Node* temp = head ;
//     int carry = 1 ;

//     while(temp != nullptr)
//     {

//         temp -> data  += carry ;
//         // so after adding carry :
//         if (temp -> data < 10)     
//         {
//             carry = 0 ;
//             break ;
//         }
//         else
//         {
//             temp -> data = 0 ;
//             carry = 1 ;
//         }
        
//         temp = temp -> next ;

//     }

//     if(carry == 1)
//     {
//         Node* newnode = new Node(carry) ; //  new Node(1) 
//         head = reverse(head) ;
//         newnode -> next = head  ;
//         return newnode ;
//     }
//     head = reverse(head) ;

//     return head ;
// }

// Time Complexity is O(3N) .





// optimal Solution (Backtracking)

int findCarry(Node* temp )
{
    if(temp -> next == nullptr) 
    {
        temp -> data += 1;
        if(temp -> data < 10)       return 0;

        temp -> data = 0;
        return 1;
    }

    int carry = findCarry(temp -> next) ;

    temp -> data += carry ;

    if(temp -> data < 10 ) return 0 ;
    
    temp -> data = 0 ;
    return 1 ;
}
   

Node* add_1_LL(Node* head)
{
    
    if (head == nullptr)        return new Node(1);
    
    int carry = findCarry(head);
    
    if(carry == 1)
    {
        Node* newhead = new Node(1);
        newhead -> next = head ;
        return newhead ;
    }
    
    return head ;
}

// Time complexity is O(N) .
// Space Complexity is O(N) , due to recursive stack space used .

int main()
{
    vector <int> arr = {9,9,9};
    Node* head = Arr2DLL(arr);

    head = add_1_LL(head);
    print(head);

    return 0 ;
}