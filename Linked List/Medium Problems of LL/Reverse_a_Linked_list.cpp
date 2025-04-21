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


// Brute force 
// swap numbers from first to last node , using stack data structure (lifo) so here we'll swap in terms of data .

// Node* reverse(Node* head)
// {
//     stack <int> st ;
//     Node* temp = head ;
    
//     while(temp != nullptr)
//     {
//         st.push(temp->data); 
//         temp = temp -> next ;
//     }

//     temp = head ;

//     while(temp != nullptr)
//     {
//         temp->data = st.top() ;
//         st.pop();

//         temp = temp -> next ;
//     }

//     return head;
// }

// Time complexity is O(2N) .
// Space complexity is O(N) , due to stack data structure .




// Optimal solution 1 (iterative method)

// Node* reverse(Node* head)
// {
//     Node* temp = head;
//     Node* prev = nullptr;

//     while(temp != nullptr)
//     {
//         Node* front = temp -> next ; // important to store it as the link will be broken in next line .
//         temp -> next  = prev ;
//         prev = temp ;
//         temp = front ;
//     }
//     return prev ; // as it will be the new head of linked list , since temp will point to nullptr .
// }

// Time complexity is O(N)  and space complexity will be O(1) .



// Optimal solution 2 (Recursive method )

Node* reverse(Node* head)
{
    if(head == nullptr || head -> next == nullptr)      return head; // BASE CASE

    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front -> next = head ;
    head->next = nullptr;

    return newHead ;
}

// Time complexity is O(N) , because of all recursive steps we are traversing the complete linked list .
// Space complexity wil be O(N) , because of stack space occupied in each recursive step .
 
int main()
{
    vector <int> arr = {9,8,7,6,5,4,3};
    Node* head = Arr2DLL(arr);

    head = reverse(head);
    print(head);

    return 0 ;
}