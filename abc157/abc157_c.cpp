#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)

int n, m, s[5], c[5];

int main(){
    cin >> n >> m;
    rep2(i, 0, m) cin >> s[i] >> c[i], s[i]--;

    rep2(ans, 0, 1000){
        string str = to_string(ans);
        if(str.length() != n) continue;

        bool ok = true;
        rep2(i, 0, n){
            rep2(j, 0, m){
                if(s[j] == i && c[j] != (int)(str[i] - '0')) ok = false;
            }
        }
        if(ok){
            cout << ans << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}