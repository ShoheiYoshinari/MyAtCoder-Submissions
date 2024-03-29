#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    string s, t;
    cin >> s >> t;
    bool ans = true;
    rep(i, s.size()){
        if(s[i] != t[i]){
            ans = false;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
} 