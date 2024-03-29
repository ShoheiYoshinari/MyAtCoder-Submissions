#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    string s;
    cin >> n >> s;

    bool ans = false;
    int good = 0;
    rep(i, n){
        if(s[i] == 'o') good++;
        else if(s[i] == 'x') ans = true;
    }
    if(good == 0) ans = true;

    if(ans) cout << "No" << endl;
    else cout << "Yes" << endl;
}