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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];


    ll ans = 0;
    rep(i, 1, n){
        ans += abs(a[i]-a[i-1]);
        b[i] = a[i]-a[i-1];
    }
    while(q--){
        ll l, r, v;
        cin >> l >> r >> v;
        l--;
        ll mae = abs(b[l]) + abs(b[r]);
        if(l != 0) b[l] += v;
        if(r != n) b[r] -= v;
        ll ato = abs(b[l]) + abs(b[r]);
        ans += (ato - mae);
        cout << ans << endl;
    }
    return 0;
}