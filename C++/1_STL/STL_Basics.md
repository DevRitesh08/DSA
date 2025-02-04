# C++ STL Notes

The Standard Template Library (STL) in C++ provides a rich set of containers, iterators, and algorithms that help you write concise and efficient code. This guide covers major containers and functions, along with their typical time and space complexities.

---

## 1. Pairs

**Description:**  
A pair stores two heterogeneous objects as a single unit. Access its elements using `.first` and `.second`.

**When to Use:**  

- To return two values from a function.
- To store two related pieces of data (like key-value pairs).

**Example:**

```cpp
#include <iostream>
#include <utility>
using namespace std;

void explainPairs() {
    pair<int, int> p1;
    cout << "Enter two integers for pair p1: ";
    cin >> p1.first >> p1.second;
    cout << "p1: " << p1.first << " " << p1.second << endl;

    // Nested pair: an int and a pair of ints
    pair<int, pair<int, int>> p2;
    cout << "Enter an integer for p2.first: ";
    cin >> p2.first;
    cout << "Enter two integers for the nested pair in p2: ";
    cin >> p2.second.first >> p2.second.second;
    cout << "p2: " << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
}
```

**Complexity:**  

- **Access:** O(1)  
- **Space:** O(1) per pair (ignoring the size of the contained objects)

---

## 2. Vectors

**Description:**  
Vectors are dynamic arrays with contiguous storage. They offer fast random access and can be resized dynamically.

**When to Use:**  

- When you need a resizable array.
- When random access is required.
- When appending elements to the end is common.

**Key Operations & Complexities:**

| Operation                 | Time Complexity (Amortized) | Space Complexity      |
|---------------------------|-----------------------------|-----------------------|
| `push_back()` / `emplace_back()` | O(1) (amortized)         | O(n) overall          |
| `pop_back()`              | O(1)                        | —  (same as TP)                   |
| `operator[]` / `at()`     | O(1)                        | —                     |
| `insert()` (middle)       | O(n)                        | —                     |
| `erase()` (middle)        | O(n)                        | —                     |
| `clear()`                 | O(n)                        | —                     |

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

void explainVectors() {
    vector<int> vec;
    vec.push_back(1);           // Append 1
    vec.emplace_back(2);        // Append 2 (more efficient for objects)
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);

    cout << "First element: " << vec[0] << ", Second element: " << vec[1] << endl;

    // Iterating using a range-based loop
    cout << "Vector elements: ";
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Erase elements from index 2 to 3 (index 4 is excluded)
    vec.erase(vec.begin() + 2, vec.begin() + 4);
    cout << "After erasing elements at index 2 and 3: ";
    for (auto val : vec)
        cout << val << " ";
    cout << endl;

    // Insertion example:
    vector<int> Ve(2, 100);  // {100, 100}
    Ve.insert(Ve.begin(), 300);       // {300, 100, 100}
    Ve.insert(Ve.begin() + 1, 2, 7);    // Insert two 7's at index 1: {300, 7, 7, 100, 100}
    
    // Swap example:
    vector<int> r = {1, 2, 3};
    vector<int> rs = {0, 9, 8};
    r.swap(rs); // r becomes {0,9,8}, rs becomes {1,2,3}
    
    // Clearing vector
    r.clear();
    cout << "After clear, size of r: " << r.size() << " (empty? " << (r.empty() ? "Yes" : "No") << ")" << endl;
}
```

---

## 3. List

**Description:**  
A doubly linked list. Elements are not stored contiguously, and insertions/deletions at any position are efficient.

**When to Use:**  

- When frequent insertions and deletions occur.
- When random access is not required.

**Key Operations & Complexities:**

| Operation            | Time Complexity | Space Complexity      |
|----------------------|-----------------|-----------------------|
| `push_back()` / `push_front()` / `emplace_front()` | O(1) | O(n) overall  |
| `insert()`           | O(1) if position is known (but O(n) to reach that position) | — |
| `erase()`            | O(1) if iterator is given (O(n) if position must be found) | — |

**Example:**

```cpp
#include <iostream>
#include <list>
using namespace std;

void explainList() {
    list<int> ls;
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);
    ls.push_front(1);
    ls.emplace_front(0);

    cout << "List elements: ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;
}
```

---

## 4. Deque (Double-Ended Queue)

**Description:**  
A container similar to vector but supports fast insertion and deletion at both the beginning and the end.

**When to Use:**  

- When you need to insert or delete elements from both ends.
- When random access is needed along with efficient front operations.

**Key Operations & Complexities:**

| Operation                | Time Complexity         | Space Complexity      |
|--------------------------|-------------------------|-----------------------|
| `push_back()` / `push_front()` | O(1) (amortized)   | O(n) overall          |
| `pop_back()` / `pop_front()`   | O(1)                | —                     |
| `operator[]`             | O(1)                    | —                     |

**Example:**

```cpp
#include <iostream>
#include <deque>
using namespace std;

void explainDeque() {
    deque<int> dq;
    dq.push_back(1);        
    dq.emplace_back(3);
    dq.push_front(9);
    dq.emplace_front(6);

    dq.pop_back();
    dq.pop_front();

    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
}
```

---

## 5. Stack

**Description:**  
A container adapter that follows Last In First Out (LIFO). Internally, it typically uses a deque or vector.

**When to Use:**  

- To store data in a LIFO order (e.g., function call stacks, undo operations).

**Key Operations & Complexities:**

| Operation        | Time Complexity | Space Complexity      |
|------------------|-----------------|-----------------------|
| `push()`         | O(1)            | O(n) overall          |
| `pop()`          | O(1)            | —                     |
| `top()`          | O(1)            | —                     |
| `empty()`, `size()` | O(1)         | —                     |

**Example:**

```cpp
#include <iostream>
#include <stack>
using namespace std;

void explainStack() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);

    cout << "Top element: " << st.top() << endl; // 5
    st.pop();
    cout << "Top element after pop: " << st.top() << endl; // 3
    cout << "Stack size: " << st.size() << endl;
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
}
```

---

## 6. Queue

**Description:**  
A container adapter that follows First In First Out (FIFO).

**When to Use:**  

- For processing tasks in order (e.g., scheduling, breadth-first search).

**Key Operations & Complexities:**

| Operation        | Time Complexity | Space Complexity      |
|------------------|-----------------|-----------------------|
| `push()`         | O(1)            | O(n) overall          |
| `pop()`          | O(1)            | —                     |
| `front()`, `back()` | O(1)         | —                     |

**Example:**

```cpp
#include <iostream>
#include <queue>
using namespace std;

void explainQueue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back() += 5; // Modifies the last element: now q becomes {1, 2, 9}
    
    cout << "Front element: " << q.front() << endl;  // 1
    q.pop(); // Removes the front element (1)
    cout << "New front element: " << q.front() << endl;  // 2
}
```

---

## 7. Priority Queue

**Description:**  
A container adapter that always gives you access to the “highest priority” element (by default, the maximum).  
It is typically implemented as a heap.

**When to Use:**  

- When you need to process elements in order of priority (e.g., Dijkstra’s algorithm, scheduling).

**Key Operations & Complexities:**

| Operation        | Time Complexity         | Space Complexity      |
|------------------|-------------------------|-----------------------|
| `push()`         | O(log n)                | O(n) overall          |
| `pop()`          | O(log n)                | —                     |
| `top()`          | O(1)                    | —                     |

**Example:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

void explainPQ() {
    // Max heap (default)
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << "Top element in max-heap: " << pq.top() << endl; // 10
    pq.pop();
    cout << "New top element after pop: " << pq.top() << endl; // 8

    // Min heap using greater<int>
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.emplace(10);

    cout << "Top element in min-heap: " << pq2.top() << endl; // 2
}
```

---

## 8. Set

**Description:**  
An ordered container that stores **unique** elements in sorted order (by default in ascending order).

**When to Use:**  

- When you need to store unique items.
- When fast lookup, insertion, and deletion (O(log n)) are required.

**Key Operations & Complexities:**

| Operation         | Time Complexity         | Space Complexity      |
|-------------------|-------------------------|-----------------------|
| `insert()`, `erase()`, `find()` | O(log n)      | O(n) overall          |
| `lower_bound()`, `upper_bound()` | O(log n)      | —                     |

**Example:**

```cpp
#include <iostream>
#include <set>
using namespace std;

void explainSet() {
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);    // Duplicate; will be ignored
    st.insert(4);
    st.insert(3);

    // Erase element 3 using iterator
    auto it = st.find(3);
    if (it != st.end())
        st.erase(it);

    // Erase elements in a range: from 2 up to (but not including) 4
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    if (it1 != st.end() && it2 != st.end())
        st.erase(it1, it2);

    cout << "Set elements: ";
    for (auto val : st)
        cout << val << " ";
    cout << endl;

    // lower_bound and upper_bound usage
    auto lb = st.lower_bound(2);  // First element >= 2
    auto ub = st.upper_bound(3);  // First element > 3
    if(lb != st.end()) cout << "Lower bound of 2: " << *lb << endl;
    if(ub != st.end()) cout << "Upper bound of 3: " << *ub << endl;
}
```

---

## 9. Multiset

**Description:**  
Similar to set but allows duplicate elements. Elements are stored in sorted order.

**When to Use:**  

- When duplicates are allowed.
- For frequency counts and scenarios where order matters.

**Key Operations & Complexities:**

| Operation         | Time Complexity         | Space Complexity      |
|-------------------|-------------------------|-----------------------|
| `insert()`, `erase()`, `find()`, `count()` | O(log n) (each operation) | O(n) overall          |

**Example:**

```cpp
#include <iostream>
#include <set>
using namespace std;

void explainMultiSet() {
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    // Erase all occurrences of 1
    ms.erase(1);  // Now multiset is empty

    // Reinsert elements for demonstration
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    cout << "Occurrences of 1: " << ms.count(1) << endl;

    // Erase a single occurrence of 1
    auto it = ms.find(1);
    if (it != ms.end())
        ms.erase(it);
}
```

---

## 10. Unordered Set

**Description:**  
An unordered set uses a hash table to store unique elements without any specific order.  
Average-case operations are O(1).

**When to Use:**  

- When order is not important.
- For fast average-case lookup, insertion, and deletion.

**Key Operations & Complexities:**

| Operation         | Average Time Complexity | Worst-Case Complexity | Space Complexity      |
|-------------------|-------------------------|-----------------------|-----------------------|
| `insert()`, `erase()`, `find()` | O(1)             | O(n) (rare)           | O(n) overall          |

**Example:**

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

void explainUnorderedSet() {
    unordered_set<int> ust;
    ust.insert(3);
    ust.insert(1);
    ust.insert(2);
    ust.insert(2); // Duplicate is not added

    cout << "Unordered set elements: ";
    for (auto val : ust)
        cout << val << " ";
    cout << endl;
}
```

---

## 11. Map

**Description:**  
A map stores key-value pairs with **unique keys** in sorted order.  
Keys are sorted automatically, and each key is associated with one value.

**When to Use:**  

- For associative arrays or dictionaries.
- When fast lookup by key is needed.

**Key Operations & Complexities:**

| Operation         | Time Complexity         | Space Complexity      |
|-------------------|-------------------------|-----------------------|
| `insert()`, `erase()`, `find()`, `lower_bound()`, `upper_bound()` | O(log n) | O(n) overall          |
| Access via `operator[]` | O(log n)         | —                     |

**Example:**

```cpp
#include <iostream>
#include <map>
using namespace std;

void explainMap() {
    map<int, int> mpp1;
    mpp1[1] = 2;
    mpp1.emplace(3, 1);
    mpp1.insert({2, 4});

    cout << "Map elements:" << endl;
    for (auto it : mpp1)
        cout << "Key: " << it.first << ", Value: " << it.second << endl;

    cout << "Value for key 1: " << mpp1[1] << endl;
    cout << "Value for key 5 (default 0): " << mpp1[5] << endl;

    auto it = mpp1.find(3);
    if (it != mpp1.end())
        cout << "Found key 3 with value: " << it->second << endl;

    auto lb = mpp1.lower_bound(2);
    auto ub = mpp1.upper_bound(3);
    if(lb != mpp1.end()) cout << "Lower bound for key 2: " << lb->first << endl;
    if(ub != mpp1.end()) cout << "Upper bound for key 3: " << ub->first << endl;
}
```

---

## 12. Multimap & Unordered Map

**Multimap:**  

- **Description:** Like `map`, but allows **duplicate keys**.
- **Note:** The `operator[]` is not available since keys aren’t unique.
- **Complexity:** Insertion, deletion, and lookup are O(log n).

**Unordered Map:**  

- **Description:** Uses a hash table to store key-value pairs.  
- **When to Use:** When order does not matter and average-case constant time operations are desired.
- **Complexity:** Average O(1) for insertion, deletion, and lookup (O(n) worst-case).

---

## 13. Extra STL Algorithms and Functions

### Custom Sorting with a Comparator

**Example:**  
Sorting a vector (or array) of pairs with a custom rule:  

- Primary: sort by the second element (ascending)
- Secondary: if equal, sort by the first element (descending)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    return p1.first > p2.first;
}

void explainSorting() {
    vector<pair<int, int>> arr = {{1, 2}, {2, 1}, {4, 1}};
    sort(arr.begin(), arr.end(), comp);
    cout << "Sorted pairs:" << endl;
    for (auto p : arr)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}
```

### Other Useful Algorithms

- **Standard Sorting:**

  ```cpp
  sort(arr, arr + n);           // Sort an array in ascending order.
  sort(v.begin(), v.end());     // Sort a vector in ascending order.
  sort(a + 2, a + 4);           // Sort a subarray.
  sort(a, a + n, greater<int>());  // Sort in descending order.
  ```

- **Counting Set Bits:**

  ```cpp
  int num = 7;
  int cnt = __builtin_popcount(num);         // For 32-bit int.
  long long large_num = 234354665432312LL;
  int cnt_ll = __builtin_popcountll(large_num); // For 64-bit int.
  ```

- **Generating Permutations:**

  ```cpp
  #include <string>
  #include <algorithm>
  
  string s = "123";
  sort(s.begin(), s.end()); // Start with the smallest permutation.
  do {
      cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));
  ```

- **Finding Maximum Element:**

  ```cpp
  int maxi = *max_element(a, a + n);
  ```

---

## Final Tips

- **Choosing the Right Container:**  
  - **Vector:** Best for dynamic arrays with random access.
  - **List:** Ideal for frequent insertions/deletions in the middle.
  - **Set/Map:** Use when you need sorted order and uniqueness.
  - **Unordered Containers:** Great for average O(1) operations when order is not important.

- **Efficiency:**  
  Always consider both the average and worst-case time complexities. STL containers have different trade-offs in terms of performance and memory overhead.
