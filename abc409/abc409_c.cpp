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
    int n, l;
    cin >> n >> l;
    vector<int> d(n-1);
    rep(i, n-1) cin >> d[i];

    vector<ll> cir(l, 0);
    cir[0]++;
    int cnt = 0;
    rep(i, n-1){
        cnt += d[i];
        cnt %= l;
        cir[cnt]++;
    }

    if(l%3 != 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i, l/3){
        ans += cir[i]*cir[l/3+i]*cir[l/3*2+i];
    }
    cout << ans << endl;
    return 0;
}