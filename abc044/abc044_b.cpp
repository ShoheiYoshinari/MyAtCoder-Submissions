#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;

    vector<int> a(26, 0);
    bool ans = true;

    rep(i, s.size()){
        a[(int)(s[i] - 'a')]++;
    }
    rep(i, 26){
        if(a[i] % 2 != 0) ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}