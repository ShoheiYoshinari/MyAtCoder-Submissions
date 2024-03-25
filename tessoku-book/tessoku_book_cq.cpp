#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i <= (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

ll n, s, a[69];
bool dp[69][10009];

int main(){
    cin >> n >> s;
    rep2(i, 1, n) cin >> a[i];

    rep2(i, 0, n){
        rep2(j, 0, s) dp[i][j] = false;
    }

    dp[0][0] = true;
    rep2(i, 1, n){
        rep2(j, 0, s){
            if(j < a[i]){
                if(dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }else{
                if(dp[i-1][j] == true || dp[i-1][j-a[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }
    if(!dp[n][s]){
        cout << "-1" << endl;
        return 0;
    }

    vector<int> ans;
    int place = n, sum = s;

    while(true){
        if(sum == 0) break;
        if(dp[place-1][sum] == true) place--;
        else{
            sum -= a[place];
            ans.push_back(place);
            place--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep2(i, 0, ans.size()-1){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;

}