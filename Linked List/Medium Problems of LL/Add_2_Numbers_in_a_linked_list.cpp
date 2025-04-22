#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
            int data;
            Node* next ;
            // constructor
            Node(int data1)
            {
                data = data1 ;
                next = nullptr ;
            }

            Node(int data1 , Node* next1)
            {
                data = data1 ;
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
    Node* mover = head ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = mover -> next ; // or prev = prev ->  next ;
    }

    return head;    // since in LL head is the key to whole LL .
}

// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Node* Add_2_Numbers(Node* head1 , Node* head2)
{
    // pointers of the numbers
    Node* temp1 = head1 ;
    Node* temp2 = head2 ;
    Node* dummynode = new Node(-1) ;
    Node* dummytemp = dummynode ;
    int carry = 0;
    int sum = 0 ;

    while(temp1 != nullptr || temp2 != nullptr || carry)
    {
        sum = carry ;
        if(temp1)
        {
            sum += temp1 -> data ;
            temp1 = temp1 -> next ;
        }   
        if(temp2)
        {
            sum += temp2 -> data ;
            temp2 = temp2 -> next ;
        }   
        Node* newnode = new Node(sum % 10) ;
        carry = sum / 10 ;
        dummytemp -> next = newnode ;
        dummytemp = dummytemp -> next ;

    }

    return dummynode->next ;
}

// Time complexity will be O(max(M,N))
// space complexity will be O(max(M,N)) The length of the new list is at most max(m,n)+1.


int main()
{
    vector <int> arr1 = {8,9} ; // this is 98 in linked list as we have stored in reverse 
    vector <int> arr2 = {1,2} ; // this is 21 in linked list as we have stored in reverse
    // hence the output is also in reverse  911
    Node* head1 = Arr2DLL(arr1);
    Node* head2 = Arr2DLL(arr2);

    Node* head = Add_2_Numbers(head1 , head2);
    // the output is also in reversed order
    print(head);

    return 0 ;
}