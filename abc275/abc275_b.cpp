#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long w = 998244353;
    long long x, y, ans;

    x = ((a%w)*(b%w))%w;
    x = (x*(c%w))%w;
    y = ((d%w)*(e%w))%w;
    y = (y*(f%w))%w;

    ans = (x + w - y)%w;

    cout << ans << endl;


}                               