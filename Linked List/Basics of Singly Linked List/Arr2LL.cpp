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

// the Arr2LL function has a time complexity of O(n) and a space complexity of O(n), where n is the number of elements in the input array.
// Each element in the array results in a new node in the linked list, requiring O(n) space.

int main()
{
    vector <int> arr = {2,3,5,7,9} ; 
    Node* head = Arr2LL(arr);
    cout<< head->data ;
}