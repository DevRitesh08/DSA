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


// Brute Force :

Node* DeleteOccurrences(Node* head)
{
    int k ;
    cout<<"Enter the number to delete its all Occurrences : ";
    cin>> k ;
    Node* temp = head ;
    while(temp != nullptr)
    {
        if(temp -> data == k)
        {
            if(temp == head)
            {
                head = head -> next ;
            }
            Node* nextnode = temp -> next ;
            Node* prevnode = temp -> back ;
            if(nextnode != nullptr)     nextnode -> back = prevnode ; 
            if(prevnode != nullptr)     prevnode -> next = nextnode ;
            delete temp ;
            temp = nextnode ;

        }
        else        temp = temp -> next ;
    }
    return head ;

}

// Time complexity is O(N) .
// space complexity is O(1) .



int main()
{
    vector <int> arr = {1,2,4,5,3,6,1,1,1,1,7,8,9,2,1,3,5,8,9,9,4,3,5} ;
    Node* head = Arr2DLL(arr);
    head = DeleteOccurrences(head);
    
    print(head);

    return 0 ;
}