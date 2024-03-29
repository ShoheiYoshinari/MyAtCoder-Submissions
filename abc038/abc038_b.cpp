#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int h[2], w[2];
    rep(i, 2) cin >> h[i] >> w[i];
    if(h[0] == h[1] || h[0] == w[1] || w[0] == h[1] || w[0] == w[1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}