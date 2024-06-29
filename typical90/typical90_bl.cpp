#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<ll> e(n+1);
    ll sum = 0;

    rep(i, 1, n){
        e[i] = a[i+1] - a[i];
        sum += abs(e[i]);
    }

    rep(i, q){
        ll l, r, v;
        cin >> l >> r >> v;
        ll f = abs(e[l-1]) + abs(e[r]);
        if(l >= 2) e[l-1] += v;
        if(r <= n-1) e[r] -= v;
        ll b = abs(e[l-1]) + abs(e[r]);
        sum += (b - f);
        cout << sum << endl;
    }
    return 0;
}