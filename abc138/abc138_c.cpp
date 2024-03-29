#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    rep(i, n) cin >> v[i];

    sort(v.begin(), v.end());

    double ans = v[0];

    for(int i = 1; i < n; i++){
        ans += v[i];
        ans /= 2;
    }
    cout << fixed << setprecision(5) << ans << endl;
}