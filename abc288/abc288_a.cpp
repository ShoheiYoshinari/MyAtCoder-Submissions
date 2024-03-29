#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i, n) cin >> a[i] >> b[i];
    
    rep(i, n) cout << a[i] + b[i] << endl;
}