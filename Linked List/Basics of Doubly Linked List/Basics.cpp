#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
            int data;
            Node* next;
            Node* back;

            //constructor
            Node(int data1 , Node* back1 , Node* next1)
            {
                data= data1 ;
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
        cout<<head->data<<"  ";
        head = head -> next ;
    }
    cout<<endl; 
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

int main()
{
    vector <int> arr = {2,3,5,7,9} ; 
    Node* head = Arr2DLL(arr);
    // cout<< head->data<<endl ;
    print(head);
}



