#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)

int main(){
    ll n, k, tmp;
    cin >> n >> k;
    vector<ll> a(k), x(n), y(n);
    rep(i, k) cin >> a[i], a[i]--;
    rep(i, n) cin >> x[i] >> y[i];

    ll res = 0;
    rep(i, n){
        ll cres = 8e18;
        for(auto &nx : a){
            cres = min(cres, (x[i] - x[nx])*(x[i] - x[nx]) + (y[i] - y[nx])*(y[i] - y[nx]));
        }
        res = max(res,cres);
    }
    cout << fixed << setprecision(15) << sqrt((double)res) << endl;


}