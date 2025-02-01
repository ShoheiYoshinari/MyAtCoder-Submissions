#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()

template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int n, m, h;
vector<int> a;
vector<vector<int>> adj;

ll cal(const vector<int>& parent){
    vector<int> height(n, 0);
    ll score = 0;

    rep(i, n){
        if (parent[i] != -1){
            height[i] = height[parent[i]] + 1;
        }
        if (height[i] <= h){
            score += (height[i] + 1) * a[i];
        }
    }
    return score;
}


vector<int> init_sol(int root){
    vector<int> parent(n, -1);
    vector<bool> seen(n, false);
    vector<int> height(n, 0);

    parent[root] = -1;
    seen[root] = true;
    height[root] = 0;

    queue<int> q;
    q.push(root);

    vector<int> no_parent;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(v == parent[u]) continue;
            if(height[u] >= h) continue;

            if(!seen[v]){
                seen[v] = true;
                parent[v] = u;
                height[v] = height[u] + 1;
                q.push(v);
            }
        }
    }


    rep(st, n){
        if(!seen[st]){
            queue<int> q;
            q.push(st);
            seen[st] = true;
            height[st] = 0;

            while(!q.empty()){
                int u = q.front(); q.pop();
                for(auto v : adj[u]){
                    if(v == parent[u]) continue;
                    if(height[u] >= h) continue;

                    if(!seen[v]){
                        seen[v] = true;
                        parent[v] = u;
                        height[v] = height[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    rep(i, n){
        if(parent[i] == -1){
            no_parent.push_back(i);
        }
    }

    for(auto node : no_parent){
        parent[node] = -1;
    }
    return parent;
}

int main() {
    cin >> n >> m >> h;
    a.resize(n);
    rep(i, n) cin >> a[i];

    adj.resize(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        if(u != v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    ll best_score = -1;
    vector<int> best_sol;

    rep(root, n){
        vector<int> sol = init_sol(root);
        ll score = cal(sol);
        if(score > best_score){
            best_score = score;
            best_sol = sol;
        }
    }

    rep(i, n) {
        if (i > 0) cout << ' ';
        cout << best_sol[i];
    }
    cout << endl;

    return 0;
}
