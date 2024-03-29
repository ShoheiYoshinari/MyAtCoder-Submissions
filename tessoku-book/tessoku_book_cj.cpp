#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <=(int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n, x, q, a[100000009];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    sort(a+1, a+n+1);
    cin >> q;
    rep(i, q){
        cin >> x;
        int ans = lower_bound(a+1, a+n+1, x) - a - 1;
        cout << ans << endl;
    }
}