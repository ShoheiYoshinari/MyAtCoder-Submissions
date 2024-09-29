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

const ll INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, ll>>> graph(N + 1);
    vector<ll> x(N + 1, INF);
    vector<bool> visited(N + 1, false);


    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, -w);
    }
    
    queue<int> q;
    
    for (int start = 1; start <= N; start++) {
        if (x[start] == INF) {
            x[start] = 0;
            q.push(start);
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                if (visited[u]) continue;
                visited[u] = true;
                
                for (auto [v, w] : graph[u]) {
                    if (x[v] == INF) {
                        x[v] = x[u] + w;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}