#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

using Graph = vector<vector<ll>>;
int n;

void BFS(Graph &G, vector<ll> &dist, ll f){
    queue<ll> que;
    que.push(f);
    dist[f] = 0;

    while(!que.empty()){
        ll v = que.front();
        que.pop();

        for(ll nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    return ;
}

int main(){
    cin >> n;
    Graph G(n);
    rep(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> dist(n, -1);
    rep(i, n){
        if(dist[i] != -1) continue;
        BFS(G, dist, i);
    }

    ll dist_max = 0;
    ll ans = 0;
    ll pos = -1;
    rep(i, n) if(dist_max < dist[i]){
        dist_max = dist[i];
        pos = i;
    }
    vector<ll> dist2(n, -1);
    BFS(G, dist2, pos);
    rep(i, n) chmax(ans, dist2[i]);

    cout << ans + 1 << endl;
    return 0;
}