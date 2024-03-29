#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    rep(i, 26){
        bool ans = true;
        rep(j, s.size()){
            if(s[j] == (char)('a' + i)) ans = false;
        }
        if(ans){
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}