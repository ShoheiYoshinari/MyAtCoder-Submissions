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
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) sum += a[i];

    if(sum <= m){
        cout << "infinite" << endl;
        return 0;
    }

    int ok = 0, ng = 1e9;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        ll tmp = 0;
        for(auto v : a) tmp += min(mid, v);
        if(tmp <= m) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}