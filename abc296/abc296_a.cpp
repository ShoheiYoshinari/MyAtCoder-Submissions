#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    string s;
    cin >> n >> s;
    bool ans = false;
    rep(i, n-1) {
        if(s[i] == s[i+1]) ans = true;
    }
    
    if(ans) cout << "No" << endl;
    else cout << "Yes" << endl;
}