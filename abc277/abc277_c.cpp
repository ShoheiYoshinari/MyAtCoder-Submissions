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

using Graph = map<ll, vector<ll>>;
ll n;
set<ll> st;

void BFS(Graph &G, ll f){
    queue<ll> que;
    que.push(f);
    st.insert(f);
    
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : G[v]){
            if(st.count(nv)) continue;
            que.push(nv);
            st.insert(nv);
        }
    }
    return ;
}

int main() {
    cin >> n;
    Graph G;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    BFS(G, 1);
    cout << *st.rbegin() << endl;
    return 0;
    
}