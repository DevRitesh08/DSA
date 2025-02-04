#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <functional>   // for greater<>
#include <string>
using namespace std;

//
// 1. Pairs
//
void explainPairs() {
    // Create a pair of two integers.
    // Access elements using .first and .second.
    pair<int, int> p1;
    
    // Prompt for input and read two integers.
    cout << "Enter two integers for pair p1: ";
    cin >> p1.first >> p1.second; // O(1) time
    cout << "p1: " << p1.first << " " << p1.second << endl;

    // Create a nested pair where the second element is itself a pair.
    pair<int, pair<int, int>> p2;
    cout << "Enter an integer for p2.first: ";
    cin >> p2.first; // O(1)
    cout << "Enter two integers for the nested pair in p2: ";
    cin >> p2.second.first >> p2.second.second; // O(1)
    cout << "p2: " << p2.first << " " 
         << p2.second.first << " " 
         << p2.second.second << endl;
}

//
// 2. Vectors
//
void explainVectors() {
    // Create an empty vector of integers.
    vector<int> vec;
    
    // Adding elements using push_back() and emplace_back().
    // Both push_back() and emplace_back() have an amortized O(1) time complexity.
    vec.push_back(1);           // Append 1 at the end.
    vec.emplace_back(2);        // Append 2 (constructs in place).
    vec.push_back(3);           // Append 3.
    vec.push_back(4);           // Append 4.
    vec.push_back(5);           // Append 5.
    vec.push_back(6);           // Append 6.
    vec.push_back(7);           // Append 7.

    // Display first two elements using the index operator (O(1)).
    cout << "\nVector Example:" << endl;
    cout << "First element: " << vec[0] 
         << ", Second element: " << vec[1] << endl;
    
    // Using a range-based for loop to print all vector elements.
    cout << "Vector elements: ";
    for (auto val : vec) {
        cout << val << " "; // O(n) overall.
    }
    cout << endl;
    
    // pop_back() removes the last element.
    // Time Complexity: O(1) time and O(1) space.
    // Note: pop_back() does not reduce the vector's capacity.
    vec.pop_back(); // Removes the element '7'
    
    // Print vector elements after pop_back().
    cout << "After pop_back(), vector elements: ";
    for (auto val : vec)
        cout << val << " ";
    cout << endl;
    
    // Erase elements from index 2 (inclusive) to index 4 (exclusive).
    // This operation has O(n) time complexity.
    vec.erase(vec.begin() + 2, vec.begin() + 4);
    
    // Print vector after erasing elements.
    cout << "After erasing indices 2 and 3, vector elements: ";
    for (auto val : vec)
        cout << val << " ";
    cout << endl;

    // Print current size and capacity.
    // Note: Capacity may be larger than size because memory is reserved.
    cout << "Current vector size: " << vec.size() << endl;
    cout << "Current vector capacity: " << vec.capacity() << endl;
}

//
// 3. List
//
void explainList() {
    // Create an empty list of integers.
    list<int> ls;

    // push_back() and push_front() are O(1) operations.
    ls.push_back(2);      // List: {2}
    ls.push_back(3);      // List: {2, 3}
    ls.push_back(4);      // List: {2, 3, 4}
    ls.push_back(5);      // List: {2, 3, 4, 5}
    ls.push_front(1);     // List: {1, 2, 3, 4, 5}
    ls.emplace_front(0);  // List: {0, 1, 2, 3, 4, 5}

    // Iterate and print the list (O(n) iteration).
    cout << "\nList Example:" << endl;
    cout << "List elements: ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;
}

//
// 4. Deque (Double-Ended Queue)
//
void explainDeque() {
    // Create an empty deque of integers.
    deque<int> dq;
    
    // Insertion at both ends (amortized O(1)).
    dq.push_back(1);        // Deque: {1}
    dq.emplace_back(3);     // Deque: {1, 3}
    dq.push_front(9);       // Deque: {9, 1, 3}
    dq.emplace_front(6);    // Deque: {6, 9, 1, 3}

    // Remove elements from both ends in O(1) time.
    dq.pop_back();          // Removes last element: now {6, 9, 1}
    dq.pop_front();         // Removes first element: now {9, 1}

    // Access first and last elements in O(1) time.
    cout << "\nDeque Example:" << endl;
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
}

//
// 5. Stack
//
void explainStack() {
    // Create a stack of integers.
    stack<int> st;
    
    // push() and emplace() are O(1) operations.
    st.push(1);         // Stack: {1}
    st.push(2);         // Stack: {2, 1}
    st.push(3);         // Stack: {3, 2, 1}
    st.push(3);         // Stack: {3, 3, 2, 1}
    st.emplace(5);      // Stack: {5, 3, 3, 2, 1}

    // top() returns the element at the top in O(1) time.
    cout << "\nStack Example:" << endl;
    cout << "Top element: " << st.top() << endl; // Should print 5
    
    // pop() removes the top element in O(1) time.
    st.pop();           // Removes 5, now top is 3
    
    // Display new top element.
    cout << "Top element after pop: " << st.top() << endl; // Should print 3
    cout << "Stack size: " << st.size() << endl;
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
}

//
// 6. Queue
//
void explainQueue() {
    // Create a queue of integers.
    queue<int> q;
    
    // push() and emplace() add elements at the back in O(1) time.
    q.push(1);         // Queue: {1}
    q.push(2);         // Queue: {1, 2}
    q.emplace(4);      // Queue: {1, 2, 4}

    // Modify the back element in O(1) time.
    q.back() += 5;     // Now queue becomes {1, 2, 9}
    
    // front() returns the first element in O(1) time.
    cout << "\nQueue Example:" << endl;
    cout << "Front element: " << q.front() << endl;  // Prints 1
    q.pop();           // Removes the front element (1), now queue: {2, 9}
    cout << "New front element: " << q.front() << endl;  // Prints 2
}

//
// 7. Priority Queue
//
void explainPQ() {
    // Max heap (default behavior).
    priority_queue<int> pq;
    // Each push/emplace operation takes O(log n) time.
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);
    
    // top() gives the maximum element in O(1) time.
    cout << "\nPriority Queue (Max Heap) Example:" << endl;
    cout << "Top element in max-heap: " << pq.top() << endl; // Should print 10
    pq.pop();  // Removes the top element (10), O(log n)
    cout << "New top element after pop: " << pq.top() << endl; // Should print 8

    // For a min-heap, use greater<int> as a comparator.
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.emplace(10);

    cout << "Priority Queue (Min Heap) Example:" << endl;
    cout << "Top element in min-heap: " << pq2.top() << endl; // Should print 2
}

//
// 8. Set
//
void explainSet() {
    // Create an empty set of integers.
    set<int> st;
    // Insertion operations are O(log n).
    st.insert(1);
    st.emplace(2);
    st.insert(2);     // Duplicate; ignored.
    st.insert(4);
    st.insert(3);

    // Find an element in O(log n) time.
    auto it = st.find(3);
    if (it != st.end())
        st.erase(it);     // Erasing by iterator is O(1).

    // Erase a range: from element with value 2 up to (but not including) 4.
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    if (it1 != st.end() && it2 != st.end())
        st.erase(it1, it2); // O(n) for the range.

    // Iterate and print set elements.
    cout << "\nSet Example:" << endl;
    cout << "Set elements: ";
    for (auto val : st)
        cout << val << " "; // O(n) iteration.
    cout << endl;

    // lower_bound() returns the first element not less than 2 (O(log n)).
    auto lb = st.lower_bound(2);
    // upper_bound() returns the first element greater than 3 (O(log n)).
    auto ub = st.upper_bound(3);
    if(lb != st.end()) cout << "Lower bound of 2: " << *lb << endl;
    if(ub != st.end()) cout << "Upper bound of 3: " << *ub << endl;
}

//
// 9. Multiset
//
void explainMultiSet() {
    // Create an empty multiset of integers.
    multiset<int> ms;
    // Insertion in a multiset is O(log n) per operation.
    ms.insert(1); // Insert 1.
    ms.insert(1); // Insert duplicate.
    ms.insert(1); // Now contains three copies of 1.

    // Erase all occurrences of 1.
    ms.erase(1);  // Erases all 1's. (O(n) worst-case for many elements)

    // Reinsert elements for demonstration.
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    // Count occurrences of 1 (O(log n)).
    cout << "\nMultiset Example:" << endl;
    cout << "Occurrences of 1: " << ms.count(1) << endl;

    // Erase a single occurrence of 1 using an iterator.
    auto it = ms.find(1); // Finds the first occurrence.
    if (it != ms.end())
        ms.erase(it);     // Erases one occurrence.
}

//
// 10. Unordered Set
//
void explainUnorderedSet() {
    // Create an empty unordered set of integers.
    unordered_set<int> ust;
    // Average-case insertion is O(1); worst-case O(n).
    ust.insert(3);
    ust.insert(1);
    ust.insert(2);
    ust.insert(2); // Duplicate ignored.

    // Iterate and print unordered set elements.
    cout << "\nUnordered Set Example:" << endl;
    cout << "Unordered set elements: ";
    for (auto val : ust)
        cout << val << " "; // No guaranteed order.
    cout << endl;
}

//
// 11. Map
//
void explainMap() {
    // Create a map from int to int.
    map<int, int> mpp1;
    // Insertion and access take O(log n) time.
    mpp1[1] = 2;        // Insert key 1 with value 2.
    mpp1.emplace(3, 1); // Insert key 3 with value 1.
    mpp1.insert({2, 4}); // Insert key 2 with value 4.

    // Iterate and print map key-value pairs.
    cout << "\nMap Example:" << endl;
    cout << "Map elements:" << endl;
    for (auto it : mpp1) {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    // Accessing elements.
    cout << "Value for key 1: " << mpp1[1] << endl;
    // Accessing a non-existent key creates it with a default value (0 for int).
    cout << "Value for key 5 (default 0): " << mpp1[5] << endl;

    // Find an element (O(log n)).
    auto it = mpp1.find(3);
    if (it != mpp1.end())
        cout << "Found key 3 with value: " << it->second << endl;

    // lower_bound() and upper_bound() operations.
    auto lb = mpp1.lower_bound(2); // First key not less than 2.
    auto ub = mpp1.upper_bound(3); // First key greater than 3.
    if(lb != mpp1.end()) cout << "Lower bound for key 2: " << lb->first << endl;
    if(ub != mpp1.end()) cout << "Upper bound for key 3: " << ub->first << endl;
}

//
// 12. Custom Sorting with a Comparator
//
bool comp(pair<int, int> p1, pair<int, int> p2) {
    // Primary: sort by the second element (ascending)
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    // Secondary: if second elements are equal, sort by first element (descending)
    return p1.first > p2.first;
}

void explainSorting() {
    // Create a vector of pairs.
    vector<pair<int, int>> arr = {{1, 2}, {2, 1}, {4, 1}};
    
    // sort() with our custom comparator.
    sort(arr.begin(), arr.end(), comp);
    
    // Print the sorted pairs.
    cout << "\nCustom Sorting Example:" << endl;
    cout << "Sorted pairs:" << endl;
    for (auto p : arr)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}

//
// 13. Extra STL Algorithms and Functions
//
void explainExtra() {
    cout << "\nExtra STL Algorithms Example:" << endl;
    
    // Standard Sorting examples:
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);  // Sort array in ascending order.
    cout << "Sorted array (ascending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Sorting in descending order.
    sort(arr, arr + n, greater<int>());
    cout << "Sorted array (descending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Counting set bits in an integer.
    int num = 7;
    int cnt = __builtin_popcount(num); // For 32-bit int.
    cout << "Number of set bits in " << num << ": " << cnt << endl;

    // Generating permutations of a string.
    string s = "123";
    sort(s.begin(), s.end()); // Ensure starting with the smallest permutation.
    cout << "Permutations of string \"123\":" << endl;
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // Finding the maximum element in an array.
    int maxi = *max_element(arr, arr + n);
    cout << "Maximum element in the array: " << maxi << endl;
}

//
// Main function: Calls all the example functions
//
int main() {
    // Uncomment or call each function as desired to test its functionality.
    cout << "STL Demonstrations:" << endl;
    
    explainPairs();       // Demonstrates pairs.
    explainVectors();     // Demonstrates vector operations.
    explainList();        // Demonstrates list operations.
    explainDeque();       // Demonstrates deque operations.
    explainStack();       // Demonstrates stack operations.
    explainQueue();       // Demonstrates queue operations.
    explainPQ();          // Demonstrates priority queue operations.
    explainSet();         // Demonstrates set operations.
    explainMultiSet();    // Demonstrates multiset operations.
    explainUnorderedSet();// Demonstrates unordered set operations.
    explainMap();         // Demonstrates map operations.
    explainSorting();     // Demonstrates custom sorting.
    explainExtra();       // Demonstrates extra STL algorithms.
    
    return 0;
}
