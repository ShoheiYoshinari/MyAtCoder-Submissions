#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    const ll b = 1ll<<40;
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    mcf_graph<int, ll> g(n*2 + 2);
    int s = n*2;
    int t = n*2 + 1;

    rep(i, n){
        rep(j, n){
            g.add_edge(i, j+n, 1, b - a[i][j]);
        }
    }

    rep(i, n){
        g.add_edge(s, i, k, 0);
        g.add_edge(i+n, t, k, 0);
    }

    g.add_edge(s, t, n*k, b);

    auto [max_flow, min_cost] = g.flow(s, t, n*k);

    vector<string> grid(n, string(n, '.'));
    const auto &edges = g.edges();
    for(const auto &e : edges){
        if(e.from == s || e.to == t || e.flow == 0) continue;
        grid[e.from][e.to-n] = 'X';
    }
    
    cout << b*n*k - min_cost << endl;
    rep(i, n) cout << grid[i] << endl;
    return 0;
}