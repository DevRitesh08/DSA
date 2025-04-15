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




Node* Insertion_of_head(Node* head)
{
    int val;
    cout<<"Enter the value to add : ";
    cin>>val;

    if(head == nullptr)     return nullptr ;

    Node* newhead = new Node(val) ;
    newhead -> next = head ;
    head->back = newhead ;
    
    return newhead;
}




Node* Insertion_of_tail(Node* head) // for practise do insertion of node before tail .
{
    int val;
    cout<<"Enter the value to add : ";
    cin>>val;

    if(head == nullptr)     return new Node(val) ; 
    if(head -> next == nullptr)
    {
        Node* newhead = new Node(val) ;
        head -> next = newhead ;
        newhead->back = head ;
    
        return head;
    }

    Node* temp = head ;

    while(temp->next != nullptr) //temp points to the last node after thuis loop ; temp->next is nullptr.
    {
        temp = temp -> next ;
    }

    Node* newtail = new Node(val) ;
    temp -> next = newtail ;
    newtail -> back = temp ;
    
    return head;
}




Node* Insertion_of_Kth_Node(Node* head)
{
    int val, k;
    cout<<"Enter the value to add : ";
    cin>>val;
    cout<<"Enter the position to add the node : ";
    cin>>k;

    if(head == nullptr)
    {
        if(k == 1)      return new Node(val) ; 
        else        
        {
            cout<<"not possible !!";
            return nullptr;
        }
    }
    if(k == 1)
    {
        Node* temp = new Node(val);
        temp -> next = head ;
        head -> back = temp ;
        return temp ; 
    }
    
    int cnt = 0 ;
    Node* temp = head ;

    while(temp != nullptr) //temp points to the last node; temp->next is nullptr.
    {
        cnt++ ;
        if(cnt == k - 1)
        {
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            newnode->back = temp;
            temp->next = newnode;

            if (newnode->next != nullptr)
                newnode->next->back = newnode;

            break;

        }
        temp = temp -> next ;
    }

    return head;
}




Node* Insertion_of_K_Node(Node* head)
{
    int val, k;
    cout<<"Enter the value to add : ";
    cin>>val;
    cout<<"Enter the node value before which new node should appear : ";
    cin>>k;

    if(head == nullptr)
    {
        if(k == 1)      return new Node(val) ; 
        else        cout<<"not possible !!";
    }
    if( head -> data == k)
    {
        Node* temp = new Node(val);
        temp -> next = head ;
        head -> back = temp ;
        return temp ; 
    }
    
    Node* temp = head ;

    while(temp != nullptr) //temp points to the last node; temp->next is nullptr.
    {
        if(temp-> next -> data == k )
        {
            Node* newnode = new Node(val);
            newnode -> next = temp -> next ;
            temp -> next = newnode ;
            break;

        }
        temp = temp -> next ;
    }

    return head;
}






int main()
{
    vector <int> arr = {2,3,8,9,4,7,5};
    Node* head = Arr2DLL(arr);
    
    // head = Insertion_of_head(head) ;

    // head = Insertion_of_tail(head) ;

    // head = Insertion_of_Kth_Node(head) ;

    head = Insertion_of_K_Node(head) ;
    
    print(head);

    return 0 ;
}
