#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a, T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a, T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // 数列をソート
    sort(all(a));

    // 残す部分列の長さ
    ll m = n - k;
    ll ans = LLONG_MAX; // 最小化するため、十分大きな値で初期化

    // 部分列の最大値と最小値の差を求める
    for (int i = 0; i <= n - m; ++i) {
        ll res = a[i + m - 1] - a[i];
        chmin(ans, res);
    }

    cout << ans << endl;
    return 0;
}
