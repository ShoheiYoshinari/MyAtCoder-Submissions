#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    bool ans = true;
    rep(i, n){
        if(s[i] == t[i]) continue;
        if(s[i] == '0'){
            if(t[i] == '0' || t[i] == 'o') continue;
        }
        if(s[i] == 'o'){
            if(t[i] == '0' || t[i] == 'o') continue;
        }
        if(s[i] == '1'){
            if(t[i] == '1' || t[i] == 'l') continue;
        }
        if(s[i] == 'l'){
            if(t[i] == '1' || t[i] == 'l') continue;
        }
        ans = false;

    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}