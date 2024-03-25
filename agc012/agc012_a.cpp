#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)

int n, a[300009];

int main(){
    cin >> n;
    rep(i, n*3){
        cin >> a[i];
    }
    sort(a+1, a+3*n+1);
    reverse(a+1, a+3*n+1);

    ll ans = 0;
    rep(i, n){
        ans += a[i*2];
    }
    cout << ans << endl;






}