#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> s(n),t(m);
    rep(i, n) {
        cin >> s[i];
        s[i] %= 1000;
    }
    rep(i, m) cin >> t[i];
    int cnt = 0;
    rep(i, n) {
        rep(j, m) {
            if(s[i] == t[j]){
                cnt++;
                break;
            }

        }
    }
    cout << cnt << endl;

}