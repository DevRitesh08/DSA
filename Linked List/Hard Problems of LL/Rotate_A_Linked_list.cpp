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

//  Brute Force Approach :

Node* findNthNode(Node* temp , int k)
{
    int cnt = 1 ;
    while(temp != nullptr)
    {
        if(cnt == k)    return temp ;
        cnt++ ;
        temp = temp -> next ;
    }
    return temp ;
}

Node* Roatate_by_K(Node* head)
{
    int k ;
    cout<<"Enter the value of k to ratate a linked list by k places : ";
    cin>>k ;

    if(head == nullptr || k == 0 )      return head ;

    Node* tail = head ;
    int length = 1;
    while(tail -> next != nullptr)  // O(N)
    {
        length++ ;
        tail = tail -> next ;
    }

    if(k % length == 0)      return head ;
    k = k % length ;
    // attach the tail to the head .
    tail -> next = head ;

    Node* newLastnode = findNthNode(head , length - k) ;    // O(N)

    head = newLastnode -> next ;
    newLastnode -> next = nullptr ;
    
    return head ;
}

// Time complexity is O(2N) .


int main()
{
    vector <int> arr = {1,2,3,4,5,6,7,8,9} ;
    Node* head = Arr2LL(arr);
    head = Roatate_by_K(head);
    
    print(head);

    return 0 ;
}