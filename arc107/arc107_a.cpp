#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long a, b, c, ans;
    cin >> a >> b >> c;
    long long w = 998244353;
    a = a*(a+1)/2;
    b = b*(b+1)/2;
    c = c*(c+1)/2;
    a %= w;
    b %= w;
    c %= w;
    ans = a*b%w*c%w;
    cout << ans << endl;


}