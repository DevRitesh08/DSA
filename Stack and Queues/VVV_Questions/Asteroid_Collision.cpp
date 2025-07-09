#include<bits\stdc++.h>
using namespace std ;

class Solution {
public:

    /*
        [5, 10, -5]
        [5, 10, 6, -5]
        [5, 6, 4]
        [-4, -6]

        [3, 4, 5, 6, -4]
        1. negative flushes positive
        2. slower one gets flushed (both positive and negative)
    */
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> s;
        for (int val : asteroids) {
            if (s.empty()) {
                s.push(val);
                continue;
            } 

            if (val < 0) {
                while (!s.empty() && (s.top() > 0 && s.top() < val * -1)) {
                    s.pop();
                }
                if (!s.empty() && s.top() > 0 && s.top() > val * -1) {
                    continue;
                } else if (!s.empty() && s.top() > 0 && s.top() == val * -1) {
                    s.pop();
                    continue;
                } else {
                    s.push(val);
                }
            } else {
                s.push(val);
            }
        }

        vector<int> ans(s.size(), 0);
        for (int i = ans.size() - 1; i >= 0; --i) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5 , -25 , -43};
    vector<int> result = sol.asteroidCollision(asteroids);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}