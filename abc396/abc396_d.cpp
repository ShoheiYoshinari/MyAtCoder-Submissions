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

ll ans = INF<ll>();
int n, m;
vector<bool> seen;
void dfs(vector<vector<pair<int, ll>>> &G, int v, vector<bool> seen, ll x) {
    seen[v] = true;
    if(v == n-1){
        chmin(ans, x);
        return ;
    }
    for (auto [nv, w] : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv, seen, x^w);
    }
}

int main(){
    cin >> n >> m;
    vector<vector<pair<int, ll>>> G(n);
    rep(i, m){
        int a, b; ll w;
        cin >> a >> b >> w;
        a--, b--;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }

    seen.assign(n, false);
    dfs(G, 0, seen, 0);
    cout << ans << endl;
    return 0;
}