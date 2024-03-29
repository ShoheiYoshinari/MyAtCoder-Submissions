#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    long long ans = 1;
    sort(c.begin(), c.end());
    rep(i, n){
        ans = ans * max(0, c[i] - i) % (int)(1e9 + 7);
    }

    cout << ans << endl;
}