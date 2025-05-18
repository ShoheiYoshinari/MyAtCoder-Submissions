#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    int n;
    cin >> n;
    vector<int> P(n);
    rep(i, n) cin >> P[i];

    vector<int> up(n, 0), dec(n, 0), inc_rev(n, 0);
    rep(i, 1, n) {
        up[i] = (P[i-1] < P[i] ? up[i-1] + 1 : 0);
    }
    for(int i = n - 2; i >= 0; --i) {
        dec[i] = (P[i] > P[i+1] ? dec[i+1] + 1 : 0);
    }
    for(int i = n - 2; i >= 0; --i) {
        inc_rev[i] = (P[i] < P[i+1] ? inc_rev[i+1] + 1 : 0);
    }

    vector<ll> diff(n+2, 0);
    rep(p, 1, n-1) {
        if (P[p-1] < P[p] && P[p] > P[p+1]) {
            int start_q = p + 1;
            int end_q   = p + dec[p];
            if (start_q <= end_q) {
                diff[start_q]     += up[p];
                diff[end_q + 1]   -= up[p];
            }
        }
    }

    ll ans = 0, cur = 0;
    rep(q, 1, n-1) {
        cur += diff[q];
        if (P[q-1] > P[q] && P[q] < P[q+1]) {
            ans += cur * inc_rev[q];
        }
    }

    cout << ans << endl;
    return 0;
}
