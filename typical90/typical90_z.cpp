#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) <= (r); ++(i))
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
vector<ll> dist(1e5, -1);
ll n;
void BFS(Graph &G, vector<ll> &dist, ll f){
    queue<ll> que;
    que.push(f);
    dist[f] = 0;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(auto nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    return ;
}

int main() {
    cin >> n;
    Graph G(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans1, ans2;
    dist[0] = 0;
    BFS(G, dist, 0);
    rep(i, n){
        if(dist[i]%2 == 0) ans1.push_back(i);
        else ans2.push_back(i);
    }
    sort(all(ans1)), sort(all(ans2));
    if(ans1.size() > ans2.size()){
        rep(i, n/2) cout << ans1[i] + 1 << ' ';
    }else{
        rep(i, n/2) cout << ans2[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}