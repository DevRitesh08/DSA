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

    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i] , prev , nullptr);
        prev -> next = temp;
        prev = temp ; // or prev = prev ->  next ;
    }

    return head;    // since in LL head is the key to whole LL .
}




// Deletion of head of doubly linked list .

Node* deletion_of_head(Node* head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        delete head ;
        return nullptr ;
    }

    Node* prev = head;
    head = head->next ;
    head ->back = nullptr ;
    prev ->next = nullptr ;
    delete prev ;
    return head ;

}




// Deletion of tail of doubly linked list .

Node* deletion_of_tail(Node* head)
{
    if(head == nullptr || head -> next == nullptr)    
    {
        delete head ; 
        return nullptr ;
    }

    Node* tail = head ;
    while(tail -> next != NULL)
    {
        tail = tail -> next ;
    }

    Node* newtail = tail -> back ;
    newtail -> next = nullptr ;
    tail -> back = nullptr ;
    delete tail ;

    return head ;

}




// Deletion of Kth node of doubly linked list .
// k lies between 1 to n  (1 based indexing )

Node* deletion_of_Kth_Node(Node* head)
{
    int k;
    cout<<"Enter the kth node to delete : ";
    cin>>k;

    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return head;
    }
    
    int cnt = 0 ;
    Node* kNode = head ;

    while(kNode != nullptr)
    {
        cnt++ ;
        if(cnt == k)    break;
        kNode = kNode -> next ;
    }

    Node* prev = kNode->back ;
    Node* front = kNode->next ;

    // only node in the list
    if(prev == nullptr && front == nullptr)
    {
        delete kNode ;
        return nullptr;
    }
    // head node
    else if(prev == NULL)
    {
        return  deletion_of_head(head);
    }
    // tail node
    else if(front == NULL)
    {
        return  deletion_of_tail(head);
    }

    // middle node
    prev ->next = front ;
    front ->back = prev ;

    kNode -> next = nullptr ;
    kNode -> back = nullptr ;
    delete kNode ;
    // ...is technically unnecessary and could even be removed without changing the behavior of the function as long as you’re not accessing kNode after deleting it.
    // but still it's necessary to set kNode->next = nullptr and kNode->back = nullptr before deleting the node in a doubly linked list because of  Safety (in debugging or later use) , Code conventions / clarity .

    return head ;

}

// Time complexity will be O(N) , where N  is the number of elements in the doubly linked list .




// Deletion of K node of doubly linked list (by value) 

Node* deletion_of_K_Node(Node* head)
{
    int val;
    cout << "Enter the value of node to delete: ";
    cin >> val;

    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return head;
    }

    Node* kNode = head;

    // Traverse the list to find the node with the given value
    while (kNode != nullptr)
    {
        if (kNode->data == val)
            break;
        kNode = kNode->next;
    }

    // Value not found
    if (kNode == nullptr)
    {
        cout << "Value not found in the list." << endl;
        return head;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    // Only one node in the list
    if (prev == nullptr && front == nullptr)
    {
        delete kNode;
        return nullptr;
    }
    // Deleting the head node
    else if (prev == nullptr)
    {
        front->back = nullptr;
        kNode->next = nullptr;
        delete kNode;
        return front; // new head
    }
    // Deleting the tail node
    else if (front == nullptr)
    {
        prev->next = nullptr;
        kNode->back = nullptr;
        delete kNode;
        return head;
    }

    // Deleting a middle node
    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;

    return head;
}



int main()
{
    vector <int> arr = {3,12,45,1,7,78,1,4,121,767};
    Node* head = Arr2DLL(arr);
    
    // head = deletion_of_head(head) ;

    // head = deletion_of_tail(head) ;

    // head = deletion_of_Kth_Node(head) ;

    head = deletion_of_K_Node(head) ;
    
    print(head);

    return 0 ;
}