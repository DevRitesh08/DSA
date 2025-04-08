// ​In C++, NULL and nullptr both represent null pointers, but they differ in type safety and usage.​

// NULL:

// Defined as a macro, typically 0.​

// Can be assigned to any pointer type, but also to integer types, potentially causing ambiguities.​

// In function overloading, using NULL can lead to ambiguous calls if overloaded functions accept both pointer and integer types.​

// nullptr:

// A keyword introduced in C++11, representing a null pointer constant of type std::nullptr_t.​

// Can only be assigned to pointer types, preventing accidental assignments to non-pointer types.​

// In function overloading, nullptr resolves ambiguity by clearly indicating a null pointer, ensuring the correct function overload is called.


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
            int data;
            Node* next;
            
            Node(int data1){
                data = data1;
                next = nullptr;
            }
};

Node* Arr2LL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head ;

    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp ; // or mover = mover ->  next ;
    }

    return head;    // since in LL head is the key to whole LL .
}

void print(Node* head)
{
    while(head != nullptr)
    {
        cout<<head->data<<"  ";
        head = head -> next ;
    }
    cout<<endl; 
}

// Deletion of Head node .

Node* Deletion_of_Head(Node* head)
{
    if(head == nullptr)     return head ;// nth to delete !!
    Node* temp = head;
    head = head->next ;
    free(temp) ; // or delete temp ;   ==> in java garbage collector deals with it so there is no need to worry about this there .
    return head ;
}

// Deletion of Tail node .

Node* Deletion_of_Tail(Node* head)
{
    if( head == nullptr || head ->next == nullptr)     return nullptr ;
    Node* temp = head;

    while (temp->next->next != nullptr)
    { 
        temp = temp ->next ;
    }
    
    delete temp -> next ;
    temp -> next = nullptr ;
    return head ;
    
}



// Deletion of Kth(Position) node .

Node* Deletion_of_Kth(Node* head)
{
    int k;
    cout<<"Enter the position of node to delete : ";
    cin>> k ;

    if( head == nullptr )     return nullptr ;

    if(k == 1)
    {
        Node* temp = head;
        head = head -> next ;
        free (temp) ;
        return head ;
    }

    int cnt = 0 ;
    Node* temp = head ;
    Node* prev = nullptr ;

    while(temp != nullptr)
    {
        cnt++ ;
        if(cnt == k)
        {
            prev -> next = prev ->next ->next ;
            free(temp) ;
            break;
        }

        prev = temp ;
        temp = temp -> next ;
    }

    return head ;
    
}

// Time complexity will be O(K) .



// Deletion of Kth node by value .

Node* Deletion_by_value(Node* head)
{
    int val;
    cout<<"Enter the value of node to delete : ";
    cin>> val ;

    if( head == nullptr )     return nullptr ;

    if( head->data == val )
    {
        Node* temp = head;
        head = head -> next ;
        free (temp) ;
        return head ;
    }

    Node* temp = head ;
    Node* prev = nullptr ;

    while(temp != nullptr)
    {
        if( temp->data == val)
        {
            prev -> next = prev ->next ->next ;
            free(temp) ;
            break;
        }

        prev = temp ;
        temp = temp -> next ;
    }

    return head ;
    
}

// Time complexity will be O(val) .



int main()
{
    vector <int> arr = {1,3,5,7,9} ; 
    Node* head = Arr2LL(arr);

    // head = Deletion_of_Head(head);
    // print(head);
    
    // head = Deletion_of_Tail(head);
    // print(head);
    
    // head = Deletion_of_Kth(head);
    // print(head);
    
    head = Deletion_by_value(head);
    print(head);
}