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
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(46, 0), b(46, 0), c(46, 0);
    rep(i, n){
        ll aa; cin >> aa;
        a[aa%46]++;
    }
    rep(i, n){
        ll bb; cin >> bb;
        b[bb%46]++;
    }
    rep(i, n){
        ll cc; cin >> cc;
        c[cc%46]++;
    }

    ll ans = 0;
    rep(i, 46){
        rep(j, 46){
            rep(k, 46){
                if((i+j+k)%46 == 0) ans += a[i]*b[j]*c[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}