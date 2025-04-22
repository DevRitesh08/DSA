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



// Brute Force :


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

Node* LastGroupNode(Node* temp , int k)
{
    while(temp -> data != k)
    {
        temp = temp -> next ;
    }
    cout<<temp->data ;
    return temp ;
}


// Node* Reverse_k_size(Node* head)
// {
//     int k ;
//     cout<<"Enter the value of group size to reverse : ";
//     cin>>k ;

//     Node* temp = head ;
//     Node* kthnode = LastGroupNode( head , k);

// }





int main()
{
    vector <int> arr = {1,2,3,4,5,6,7,8,9} ;
    Node* head = Arr2LL(arr);
    head = LastGroupNode(head , 3);
    
    // print(head);

    return 0 ;
}