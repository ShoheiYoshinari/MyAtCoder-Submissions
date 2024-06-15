#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    deque<char> t;
    bool reverse_flag = false;

    // Construct the intermediate string T
    for (char c : s) {
        if (c == 'R') {
            reverse_flag = !reverse_flag;
        } else {
            if (reverse_flag) {
                t.push_front(c);
            } else {
                t.push_back(c);
            }
        }
    }

    // Convert deque to string
    string tmp(t.begin(), t.end());
    if (reverse_flag) {
        reverse(tmp.begin(), tmp.end());
    }

    // Remove consecutive duplicates
    vector<char> ans;
    for (char c : tmp) {
        if (!ans.empty() && ans.back() == c) {
            ans.pop_back();
        } else {
            ans.push_back(c);
        }
    }

    // Output the result
    for (char c : ans) {
        cout << c;
    }
    cout << endl;

    return 0;
}
