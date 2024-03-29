#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    rep(i, n){
        cin >> l[i];
    }
    int ans = 0;
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());
    rep(i, k) ans += l[i];
    cout << ans << endl;

}