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



// Brute Force : (linear search)

// vector<pair<int, int>> findpairs(Node* head)
// {
//     int k ;
//     cout<<"enter the value of k to find possible pairs : ";
//     cin>>k ;

//     vector<pair<int, int>> result;
//     Node* temp1 = head ;
//     // Node* temp2 = head -> next ;/*not that good observe below */
    
//     while(temp1 != nullptr /* && temp1->data + temp2->data <= sum */) // remove the commented part when the linked list is sorted in ascending order .
//     {
//         Node* temp2 = temp1->next;  // reset temp2 for each temp1 , reduces time 

//         while (temp2 != nullptr) 
//         {
//             if (temp1->data + temp2->data == k) 
//             {
//                 result.push_back({temp1->data, temp2->data});
//             }

//             temp2 = temp2->next;
//         }
//         temp1 = temp1->next;
//     }

//     return result ;
// }

// Time complexity is O(N^2) .



// Better approach (using 2 pointers ==> only work when linked list is sorted)

Node* findtail(Node* head)
{
    while(head -> next != nullptr)  head = head -> next ;

    return head ;
}

vector<pair<int, int>> findpairs(Node* head)
{
    int k ;
    cout<<"enter the value of k to find possible pairs : ";
    cin>>k ;

    vector<pair<int, int>> result;
    Node* start = head ;
    Node* end = findtail(head) ;    // O(N)

    if(head == nullptr)     return result ;

    while( start->data < end->data )    // O(N)
    {
        int sum = start->data + end->data;
        if(sum == k)
        {
            result.push_back({start->data , end->data});
            start = start -> next ;
            end = end -> back ;
        }
        else if(sum > k)     end = end -> back ;
        else        start = start -> next ;
    }

    return result ;
}

// Time complexity will be O(2N) .
// Space complexity is O(1) , since the vector of pair is used to return the answer .






int main()
{
    vector <int> arr = {1,2,3,4,5,6,7,8,9} ;
    Node* head = Arr2DLL(arr);
    vector<pair<int, int>> findP= findpairs(head);
    cout << "\nPairs with the given sum:\n";

    for (auto p : findP) 
    {
        cout << p.first << "  " << p.second << "\n";
    }

    return 0 ;
}