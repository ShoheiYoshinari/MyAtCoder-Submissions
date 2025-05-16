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
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    vector<vector<int>> a(n);
    rep(i, m){
        int k;
        cin >> k;
        rep(j, k){
            int x;
            cin >> x;
            x--;
            a[x].push_back(i);
        }
    }

    ll ans = HINF<ll>();
    rep(i, 1<<(2*n)){
        vector<int> seen(m);
        rep(j, 2*n){
            if((i >> j) & 1){
                for(auto x : a[j%n]) seen[x]++;
            }
        }

        bool ok = true;
        rep(i, m){
            if(seen[i] < 2) ok = false;
        }
        if(ok){
            ll tmp = 0;
            rep(j, 2*n){
                if((i >> j) & 1){
                    tmp += c[j%n];
                }
            }
            chmin(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}