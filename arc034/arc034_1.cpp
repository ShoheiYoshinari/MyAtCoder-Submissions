#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    double a, b, c, d,e;
    double ans = 0.0;
    rep(i, n) { 
        cin >> a >> b >> c >> d >> e;
        double res = 0.0;
        res += a + b + c + d;
        res += e * 110.0/900.0;
        ans = max(ans,res);
    }
    cout << fixed << setprecision(15) << ans << endl;
}