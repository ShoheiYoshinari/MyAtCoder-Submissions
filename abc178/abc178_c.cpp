#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

ll n;
const ll mod = 1000000007;

ll powmod(ll x, ll y){
    ll res = 1;
    rep(i, y){
        res = res*x%mod;
    }
    return res;
}

int main(){
    cin >> n;
    ll ans = powmod(10, n) - powmod(9, n)*2 + powmod(8, n);
    ans %= mod;
    ans = (ans+mod)%mod;
    cout << ans << endl;
    return 0;
}

