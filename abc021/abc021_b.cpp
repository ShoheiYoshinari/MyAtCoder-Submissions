#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const double pi = 3.141592653589793238;
const int INF = 2147483647;
const ll INFLL = 1LL << 62;
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define rep(i, r, n) for (int i = r; i < (int)n; i++)
#define pb push_back


void solve(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    set<int> p;
    p.insert(a);
    rep(i, 0, k){
        int t;
        cin >> t;
        p.insert(t);
    }
    p.insert(b);

    if(p.size() == k+2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;

}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}