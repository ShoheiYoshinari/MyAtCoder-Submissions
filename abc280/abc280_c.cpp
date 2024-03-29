#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s, t;
    cin >> s >> t;
    rep(i, t.size()){
        if(s[i] != t[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
}