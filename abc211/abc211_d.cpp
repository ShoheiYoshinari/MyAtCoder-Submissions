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
using mint = modint1000000007;
using Graph = vector<vector<int>>;

struct BFS {
    Graph G;
    vector<int> dist;
    vector<int> color;
    BFS(const Graph& G) : G(G), dist(G.size(), -1), color(G.size(), -1) {}

    // 単一始点最短経路
    mint shortest_path(int start) {
        queue<int> q;
        dist[start] = 0;
        vector<mint> cnt(G.size(), 0);
        cnt[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int nv : G[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    cnt[nv] = cnt[v];
                    q.push(nv);
                }else if(dist[nv] == dist[v] + 1){
                    cnt[nv] += cnt[v];

                }
            }
        }
        return cnt[G.size()-1];
    }

    // 到達可能なノードを取得
    vector<int> reachable_nodes(int start) {
        vector<int> reachable;
        queue<int> q;
        vector<bool> visited(G.size(), false);
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            reachable.push_back(v);
            for (int nv : G[v]) {
                if (!visited[nv]) {
                    visited[nv] = true;
                    q.push(nv);
                }
            }
        }
        return reachable;
    }

    // トポロジカルソート（DAG判定）
    vector<int> topological_sort() {
        vector<int> in_degree(G.size(), 0);
        for (auto& adj : G) {
            for (int v : adj) in_degree[v]++;
        }
        queue<int> q;
        vector<int> order;
        rep(i, G.size()) if (in_degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            order.push_back(v);
            for (int nv : G[v]) {
                if (--in_degree[nv] == 0) q.push(nv);
            }
        }
        if (order.size() != G.size()) return {}; // サイクルがある場合
        return order;
    }

    // 木の直径の計算
    int tree_diameter() {
        auto bfs_farthest = [&](int start) {
            vector<int> d(G.size(), -1);
            queue<int> q;
            q.push(start);
            d[start] = 0;
            int farthest = start;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (int nv : G[v]) {
                    if (d[nv] == -1) {
                        d[nv] = d[v] + 1;
                        q.push(nv);
                        if (d[nv] > d[farthest]) farthest = nv;
                    }
                }
            }
            return make_pair(farthest, d[farthest]);
        };
        int u = bfs_farthest(0).first;
        return bfs_farthest(u).second;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);

    Graph G(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    BFS bfs(G);
    cout << bfs.shortest_path(0).val() << endl;
    return 0;
}