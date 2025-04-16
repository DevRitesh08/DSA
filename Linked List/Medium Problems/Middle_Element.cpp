#include<bits/stdc++.h>
using namespace std ;

class Node{
    public : 
            int data ;
            Node* next ;
            Node* back ;

            Node(int data1 , Node* back1 , Node* next1)
            {
                data = data1 ;
                back = back1 ;
                next = next1 ;
            }
            Node(int data1)
            {
                data = data1 ;
                back = nullptr ;
                next = nullptr ;
            }
};

void print(Node* head)
{
    while(head != nullptr)
    {
        cout<<head->data<<"   ";
        head = head -> next ;
    }

}

Node* Arr2DLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i] , prev , nullptr);
        prev -> next = temp;
        prev = temp ; // or prev = prev ->  next ;
    }

    return head;
}


// Brute Solution

// Node* middleElement(Node* head)
// {
//     Node* temp = head;
//     int cnt = 0 ;
//     while(temp != nullptr)
//     {
//         cnt++;
//         temp = temp ->next;
//     }

//     temp = head ;
//     int midNode = (cnt/2) + 1 ;
//     while(temp != nullptr)
//     {
//         midNode-- ;
//         if(midNode == 0)        break;
//         temp = temp -> next ;
//     }
//     return temp ;
// }

// Time complexity is O(N + (N/2) ) whuile SC is O(1) .




// Optimal approach ( Tortoise and hare Algorithm )

Node* middleElement(Node* head)
{
    Node* slow = head; // slow is Tortoise
    Node* fast = head; // fast is hare

    while(fast != nullptr && fast -> next != nullptr) // first condition is for even no. of nodes and second is for odd no. of nodes .
    {
        slow = slow -> next;
        fast = fast ->  next -> next ;
    }

    return slow ;
}

// Time complexity is O(N/2) . 

int main()
{
    vector<int> vec = {2,3,4,6,8,9} ;
    Node* head = Arr2DLL(vec) ;
    Node* mid = middleElement(head) ;

    // print(head) ;
    cout<<"the data of middle node is : "<<mid->data ;
    return 0 ;
}