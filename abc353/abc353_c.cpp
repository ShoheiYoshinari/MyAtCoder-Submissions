#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dr[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    const ll m = 1e8;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    ll ans = 0;
    rep(i, n) ans += a[i] * ll(n-1);

    int r = n-1;
    rep(i, n){
        ll h = m - a[i];
        auto it = lower_bound(a.begin()+i+1, a.end(), h);
        ll cnt = a.end() - it;
        ans -= m * cnt;
    }
    cout << ans << endl;

}