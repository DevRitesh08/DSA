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




// Brute force : 

// Node* sort0s1s2s(Node* head)
// {
//     int cnt0 , cnt1 , cnt2 ;
//     cnt0 = cnt1 = cnt2 = 0 ;
//     Node* temp = head ;

//     while(temp != nullptr)
//     {
//         if(temp -> data == 0)       cnt0++;
//         else if(temp -> data == 1)      cnt1++ ;
//         else if(temp -> data == 2)      cnt2++ ;

//         temp = temp -> next ;
//     }

//     temp = head ;
//     while(temp != nullptr)
//     {
//         if(cnt0 != 0 ) // of just if(cnt0)
//         {
//             temp -> data = 0;
//             cnt0-- ;
//         }  
//         else if(cnt1 != 0) 
//         {
//             temp -> data = 1 ;
//             cnt1-- ;
//         }
//         else if(cnt2 != 0) 
//         {
//             temp -> data = 2 ;
//             cnt2--;
//         }

//         temp = temp -> next ;
//     }

//     return head ;
// }

// Time complexity is O(2N) .
// Space complexity is O(1) .





// now we have to convert it from 2 pass to 1 pass hence , can't use data replacement  ==> change Links 


// Optimal Solution

Node* sort0s1s2s(Node* head)
{
    // dummy node to attach the 0 , 1 and 2 nodes , this basically forms 3 linked lists of 0 , 1 and 2 .
    Node* zeroHead = new Node(-1) ;
    Node* oneHead = new Node(-1) ;
    Node* twoHead = new Node(-1) ;

    // pointers to the dummy nodes for traversal .
    Node* zero = zeroHead ;
    Node* one = oneHead ;
    Node* two = twoHead ;

    Node* temp = head ; 

    while(temp != nullptr)
    {
        if(temp -> data == 0)
        {
            zero -> next = temp ;
            zero = zero -> next ;
        }
        else if(temp -> data == 1)
        {
            one -> next = temp ;
            one = one -> next ;
        }
        else if(temp -> data == 2)
        {
            two -> next = temp ;
            two = two -> next ;
        }
        temp = temp -> next ;
    }
    
    // Connect the three lists
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;

    two->next = nullptr;
  
    // Update head to the start of the sorted list
    head = zeroHead->next;
  
    // Free the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head ;
}

// Time complexity is O(N) .
// Space complexity is O(1) , since we are using the same nodes .



int main()
{
    vector<int> vec = {0,1,2,0,0,2,0,1,1,2,0,0,2,1,1} ;
    Node* head = Arr2DLL(vec) ;
    Node* mid = sort0s1s2s(head) ;

    print(head) ;
    // cout<<"the data of middle node is : "<<mid->data ;
    return 0 ;
}