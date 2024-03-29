#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, q, l ,r;
    cin >> n;
    int a[n+1] = {0};
    rep(i, n) cin >> a[i];
    cin >> q;

    int s[n+1] = {0};
    rep(i, n){
        if(i%2 != 0){
            s[i] = s[i-1] + a[i] - a[i-1];    
        }else{
            s[i] = s[i-1];
        }
        s[n+1] = s[n];
    }
    int x[q+1];

    rep(i, q){
        cin >> l >> r;
        int ansl = lower_bound(a+1, a+n+1, l) - a ;
        int ansr = upper_bound(a+1, a+n+1, r) - a ;

        int ans = s[ansr] - s[ansl];

        if(ansl%2 == 1) {
            ans += a[ansl] - l;
        }
        if(ansr%2 == 1) {
            ans -= a[ansr] - r;
        }
        x[i] = ans;
    }
    rep(i, q) cout << x[i] << endl;

}