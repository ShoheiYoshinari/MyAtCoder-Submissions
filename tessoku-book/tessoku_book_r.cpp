#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int n, s, a[10009];

int main(){
    cin >> n >> s;
    rep2(i, 1, n) cin >> a[i];

    bool dp[69][10009];

    dp[0][0] = true;
    rep2(i, 1, n) dp[0][i] = false;
    rep2(i, 1, n){
        rep2(j, 0, s){
            if(j < a[i]){
                if(dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if(j >= a[i]){
                if(dp[i-1][j] == true || dp[i-1][j-a[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }
    if(dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;




}