#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int n, a[100009], b[1000009];

int main(){
    cin >> n;
    rep2(i, 2, n) cin >> a[i];
    rep2(i, 3, n) cin >> b[i];

    int dp[100009];
    dp[0] = dp[1] = 0;
    dp[2] = a[2];

    rep2(i, 3, n){
        dp[i] = min(dp[i-1] + a[i], dp[i-2] + b[i]);
    }
    cout << dp[n] << endl;
    return 0;
}