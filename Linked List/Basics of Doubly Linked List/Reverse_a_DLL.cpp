#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
            int data;
            Node* next ;
            Node* back ;
            // constructor
            Node(int data1)
            {
                data = data1 ;
                back = nullptr ;
                next = nullptr ;
            }

            Node(int data1 , Node* back1 , Node* next1)
            {
                data = data1 ;
                back = back1 ;
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
    Node* prev = head ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i] , prev , nullptr);
        prev -> next = temp;
        prev = temp ; // or prev = prev ->  next ;
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




// Optimal solution

Node* reverse(Node* head)
{
    if(head == nullptr || head->next == nullptr)        return head ;

    Node* prev = nullptr ;
    Node* current = head ;

    while(current != nullptr)
    {
        prev = current -> back ;
        current -> back = current -> next ;
        current -> next = prev ;

        current = current -> back; // used insted of current = current -> next ; , to iterate since links are swapped
    }
    return prev -> back ; // it is the new head 
}

// Time complexity is O(N) .
// Space complexity is O(1) .

int main()
{
    vector <int> arr = {9,8,7,6,5,4,3};
    Node* head = Arr2DLL(arr);

    head = reverse(head);
    print(head);

    return 0 ;
}