#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int k;
    cin >> k;

    long long ans = 0;
    rep(i, k){
        rep(j, k){
            rep(l, k){
                int g1 = gcd(i, j);
                int g2 = gcd(g1, l);
                ans += g2;
            }
        }
    }
    cout << ans << endl;
}