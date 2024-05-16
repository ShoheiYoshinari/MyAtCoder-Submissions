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
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    const ll mod = 100000;
    ll n, m;
    cin >> n >> m;
    vector<ll> dist(n-1), root(m);
    rep(i, n-1) cin >> dist[i];
    rep(i, m) cin >> root[i];

    ll s[n+1];
    s[0] = 0;
    rep2(i, 1, n-1){
        s[i] = s[i-1] + dist[i-1];
    }

    ll ans = 0;
    ll pos = 0;
    rep(i, m){
        int now = pos;
        pos += root[i];
        ans += abs(s[pos] - s[now]);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;

}