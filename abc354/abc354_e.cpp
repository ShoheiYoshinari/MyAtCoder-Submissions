#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int n2 = 1<<n;
    vector<bool> dp(n2);
    rep(s, n2){
        // 今勝てるかどうか 負け:now = false
        bool now = false;
        rep(i, n) rep(j, i) if((s>>i)&1) if((s>>j)&1){
            if(a[i] == a[j] || b[i] == b[j]){
                if(!dp[s^1<<i^1<<j]) now = true;
            }
        }
        dp[s] = now;
    }
    if(dp[n2-1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}