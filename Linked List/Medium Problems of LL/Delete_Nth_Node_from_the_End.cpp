#include<bits/stdc++.h>
using namespace std ;

class Node 
{
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1) 
        {
            data = data1;
            next = next1;
        }
        Node(int data1) 
        {
            data = data1;
            next = nullptr;
        }
    };
    
void printLL(Node* head) 
{
    while (head != NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
}
    
// Brute Force :

Node* DeleteNthNodefromEnd(Node* head, int N) 
{
    if (head == NULL)       return NULL;

    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) 
    {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N) 
    {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }
    
    // Calculate the position of the previous node from the node to delete .
    int prev = cnt - N;
    temp = head;
    
    // Traverse to the node just before the one to delete
    while (temp != NULL) 
    {
        prev--;
        if (prev == 0)      break ;
        temp = temp->next;
    }
    
    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

// Time complexity is O(L) + O(L - N) ==> but in worst case O(L-N) ==> O(L) so , the overall time complexity will be O(2L) .



// Optimal Solution :

Node* DeleteNthNodefromEnd(Node* head, int N) {
    Node* fastp = head;
    Node* slowp = head;

    // Advance fastp N steps
    for (int i = 0; i < N; i++) {
        if (!fastp) return head; // N > length
        fastp = fastp->next;
    }

    // Deleting head node
    if (!fastp) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Move both pointers
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the node
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;

    return head;
}

// Time complexity is O(l) , where L is the length of linked list .
    


int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    
    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}
    
    
    