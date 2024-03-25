#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)

ll mod = 1000000007;
ll n, m, tmp, broken[100009];
ll dp[100009];

int main(){
    cin >> n >> m;
    rep(i, m){
        cin >> tmp;
        broken[tmp]++;
    }

    dp[0] = 1;
    rep2(i, 0, n){
        dp[i] %= mod;
        rep2(d, 1, 2){
            if(!broken[i+d]) dp[i+d] += dp[i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}