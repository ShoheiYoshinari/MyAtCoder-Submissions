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

using Graph = vector<vector<int>>;
vector<int> in_degree;
bool has_cycle_bfs(const Graph &G, vector<int> &in_degree){
    queue<int> q;
    rep(i, G.size()){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    int visited_cnt = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        visited_cnt++;
        for(auto nv : G[v]){
            in_degree[nv]--;
            if(in_degree[nv] == 0){
                q.push(nv);
            }
        }
    }
    return visited_cnt != G.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    map<string, int> mp;
    int cnt = 0;
    rep(i, n){
        cin >> s[i] >> t[i];
        if(mp[s[i]] == 0) mp[s[i]] = cnt++;
        if(mp[t[i]] == 0) mp[t[i]] = cnt++;
    }
    Graph G(cnt);
    vector<int> in_degree(cnt, 0);
    rep(i, n){
        G[mp[s[i]]].push_back(mp[t[i]]);
        in_degree[mp[t[i]]]++;
    }

    if(has_cycle_bfs(G, in_degree)) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}