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

struct edge{
    long long to;
    long long cost;
    edge(long long t, long long c): to(t), cost(c) {}
};
using Graph = vector<vector<edge>>;
using P = pair<long long, int>;
/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dist
    計算量：O(|E|log|V|)
    副作用：distが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dist){
    int n = G.size();
    dist.resize(n, HINF<ll>());
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto &e : G[v]){
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
}

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    Graph G(2*n);
    rep(i, n){
        G[i].emplace_back(i+n, x);
        G[i+n].emplace_back(i, x);
    }
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v, 1);
        G[v+n].emplace_back(u+n, 1);
    }

    vector<ll> dist(2*n, HINF<ll>());
    dijkstra(G, 0, dist);
    cout << min(dist[n-1], dist[2*n-1]) << endl;
    return 0;
}