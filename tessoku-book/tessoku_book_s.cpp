#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i <= (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

ll n, ww, w[109], v[109];
ll dp[109][100009];

int main(){
    cin >> n >> ww;
    rep2(i, 1, n) cin >> w[i] >> v[i];

    rep2(i, 0, n){
        rep2(j, 0, ww) dp[i][j] = -1000000000000000ll;
    }

    dp[0][0] = 0;
    rep2(i, 1, n){
        rep2(j, 0, ww){
            if(j < w[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }                
        }
    }

    ll ans = 0;
    rep2(i, 0, ww) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}