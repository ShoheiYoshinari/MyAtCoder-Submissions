#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long n;
    cin >> n;
    long long w = n%998244353;
    if(w < 0) cout << w + 998244353 << endl;
    else cout << w << endl;
}