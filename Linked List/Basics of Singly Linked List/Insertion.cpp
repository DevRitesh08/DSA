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
            
            Node(int data1 , Node* next1){
                data = data1;
                next = next1;
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

// Insertion at Head node .

Node* Inserion_of_Head(Node* head)
{
    int val ;
    cout<<"Enter the value to add infront of Linked List : ";
    cin>>val;
    
    if(head == NULL)
    {
        return new Node(val) ;
    }



    Node* temp = new Node( val , head) ;

    return temp; // as now it is the new head of Linked List .
}

// Time complexity will be O(1) .



// Insertion at Tail node .

Node* Inserion_of_Tail(Node* head)
{
    int val ;
    cout<<"Enter the value to add at the tail of Linked List : ";
    cin>>val;

    if(head == NULL)
    {
        return new Node(val) ;
    }


    Node* temp = head ;

    while(temp->next != nullptr)
    {
        temp = temp->next ;
    }
    Node* newNode = new Node( val ) ; //  Node* newNode = new Node( val , nullptr ) ; no need since we have 2  constructors and second only directly points to nullptr.
    temp->next = newNode ; // linking the last node that is temp with the inserted tail ==> newNode .

    return head; 
}

// Time complexity will be O(N) .


// Insertion at Kth(Position) node .

Node* Insertion_at_kth(Node* head)
{
    int val , k ;
    cout<<"Enter the position to add the node : ";
    cin>>k;
    cout<<"Enter the value to add at the "<<k<<"th position of Linked List : ";
    cin>>val;

    if(head == NULL)
    {
        if(k == 1)  return new Node(val) ;
        else    cout<<"not possible !!";   
    }

    if(k == 1)
    {
        Node* temp = new Node(val , head);
        return temp ;
    }

    int cnt = 0;
    Node* temp = head ;

    while(temp != nullptr)
    {
        cnt++;

        if(cnt == k-1)
        {
            Node* newnode = new Node(val);
            newnode ->next = temp->next; // crucial step as before breaking the link we must store it in newnode otherwise the leftover linked list will be lost .
            temp->next = newnode ;
            break;
        }
        temp = temp->next ;
    }

    return head; 
}
// Time complexity will be O(K) .




// Insetion the element before the value k .

Node* Inserion_before_value(Node* head)
{
    int val , k ;
    cout<<"Enter the value to insert : ";
    cin>>val;
    cout<<"Before which element : ";
    cin>>k;

    if(head == NULL)
    {
        return NULL;   
    }

    if(head->data == k)
    {
        Node* temp = new Node(val , head);
        return temp ;
    }

    int cnt = 0;
    Node* temp = head ;

    while(temp->next != nullptr)
    {
        cnt++;

        if(temp->next->data == k)
        {
            Node* newnode = new Node(val);
            newnode ->next = temp->next; // crucial step as before breaking the link we must store it in newnode otherwise the leftover linked list will be lost .
            temp->next = newnode ;
            break;
        }
        temp = temp->next ;
    }

    return head;  
}

// Time complexity will be O(val - 1) .

int main()
{
    vector <int> arr = {1,3,5,7,9} ; 
    Node* head = Arr2LL(arr);

    // head = Inserion_of_Head(head);
  
    // head = Inserion_of_Tail(head);
    
    // head = Insertion_at_kth(head);
 
    head = Inserion_before_value(head);
    

    print(head);
    

}