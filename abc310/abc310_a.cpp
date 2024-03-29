#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> d(n);
    rep(i, n) cin >> d[i];

    sort(d.begin(), d.end());
    if(p > q + d[0]) cout << q + d[0] << endl;
    else cout << p << endl;

}