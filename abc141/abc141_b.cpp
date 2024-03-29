#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    bool ans = true;
    rep(i, s.size()) {
        if(i % 2 == 0){
            if(s[i] == 'L') {
                ans = false;
                break;
            }
        } else {
            if(s[i] == 'R') {
                ans = false;
                break;
            }
        }
    }

    if(ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}