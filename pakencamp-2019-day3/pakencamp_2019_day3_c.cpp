#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    rep(i, n) rep(j, m) cin >> a[i][j];

    ll ans = -1;
    rep(f, m){
        rep2(s, f+1, m){
            ll point = 0;
            rep(i, n) point += max(a[i][f], a[i][s]);
            ans = max(ans, point);
        }
    }
    cout << ans << endl;
    return 0;

}