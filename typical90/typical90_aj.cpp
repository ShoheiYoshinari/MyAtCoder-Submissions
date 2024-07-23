#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n), t(q);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, q) cin >> t[i], t[i]--;

    ll minx = (1ll<<60);
    ll miny = (1ll<<60);
    ll maxx = -(1ll<<60);
    ll maxy = -(1ll<<60);
    rep(i, n){
        ll p1 = x[i] + y[i];
        ll p2 = y[i] - x[i];
        x[i] = p1;
        y[i] = p2;
        chmin(minx, x[i]);
        chmin(miny, y[i]);
        chmax(maxx, x[i]);
        chmax(maxy, y[i]);
    }

    rep(i, q){
        ll r1 = abs(x[t[i]] - minx);
        ll r2 = abs(y[t[i]] - miny);
        ll r3 = abs(x[t[i]] - maxx);
        ll r4 = abs(y[t[i]] - maxy);
        cout << max({r1, r2, r3, r4}) << endl;
    }
    return 0;
}