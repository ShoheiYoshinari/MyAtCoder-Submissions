#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    string s[n],t[n];
    rep(i, n) cin >> s[i] >> t[i];

    rep(i, n) {
        bool ans_1 = false,ans_2 = false;
        rep(j, n) {
            if(i != j) {
                if(s[i] == s[j] || s[i] == t[j]) ans_1 = true;
                if(t[i] == s[j] || t[i] == t[j]) ans_2 = true;
            }
        }
        if(ans_1 == true && ans_2 == true) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
    

