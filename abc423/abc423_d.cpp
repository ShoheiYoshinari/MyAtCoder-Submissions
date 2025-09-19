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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    vector<ll> ans(n);
    ll now = 0;
    ll t = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    rep(i, n){
        chmax(t, a[i]);
        while(now + c[i] > k){
            auto [e, cnt] = pq.top(); pq.pop();
            now -= cnt;
            chmax(t, e);
        }
        ans[i] = t;
        now += c[i];
        pq.push({t+b[i], c[i]});
    }

    rep(i, n) cout << ans[i] << endl;
    return 0;
}