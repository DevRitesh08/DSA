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






// Brute Force 

Node* RemoveDuplicates(Node* head)
{
    Node* temp = head ;
    while(temp != nullptr && temp -> next != nullptr) // as after the last node there can't be any duplicates .
    {
        Node* nextNode = temp -> next ;
        while(nextNode != nullptr && nextNode ->data == temp -> data)
        {
            Node* duplicate = nextnode ;
            nextNode = nextNode -> next ;
            delete duplicate ;
        }
       
        temp -> next = nextNode ;

        if(nextNode)    nextNode-> back = temp ;
        temp = temp -> next ;
    }

    return head ;
}

// Time complexity WILL NOT BE O(N^2) ===> IT'LL BE o(N) ==> DO DRY RUN !!!!!






int main()
{
    vector <int> arr = {1,1,1,1,1,2,3,4,4,4,4,4,5,6,7,7,7,7,8,8,8,8,8,8,9} ;
    Node* head = Arr2DLL(arr);
    head = RemoveDuplicates(head) ;
    print(head) ;
    return 0 ;
}