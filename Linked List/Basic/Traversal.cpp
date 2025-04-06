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

void LLtraversal(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<"  ";
        temp = temp -> next;
    }
}

// Time complexity will be O(N) .

int main()
{
    vector <int> arr = {2,3,5,7,9} ; 
    Node* head = Arr2LL(arr);
    LLtraversal(head);
}