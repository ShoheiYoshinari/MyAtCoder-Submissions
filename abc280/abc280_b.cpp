#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int n;
    cin >> n;
    int s[n+1];
    rep(i, n) cin >> s[i];

    int ans[n+1];
    s[0] = 0;
    rep(i, n){
        ans[i] = s[i] - s[i-1];
        cout << ans[i] << ' ';
    }
    cout << endl;
}