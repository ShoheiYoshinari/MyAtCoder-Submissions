#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int l, h, n;
    cin >> l >> h >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n){
        if(h < a[i]) cout << -1 << endl;
        else if(l <= a[i] && h >= a[i]) cout << 0 << endl;
        else if(l > a[i]) cout << l - a[i] << endl;
    }
}