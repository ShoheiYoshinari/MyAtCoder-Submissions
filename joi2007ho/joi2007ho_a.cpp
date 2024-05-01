#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

ll n, k;
ll a[100009];
ll s[100009];

int main(){
    cin >> n >> k;
    rep2(i, 1, n) cin >> a[i];

    s[0] = 0;
    rep2(i, 1, n) s[i] = s[i-1] + a[i];

    ll ans = -1000000000;
    rep2(i, k, n){
        ans = max(ans, s[i] - s[i-k]);
    }
    cout << ans << endl;
    return 0;
}