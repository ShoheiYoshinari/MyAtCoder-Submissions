#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip> // for setprecision

using namespace std;

using ll = long long;
using Graph = vector<vector<int>>;

int main() {
    ll N, M;
    cin >> N >> M;

    Graph G(N + 1);
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    vector<ll> dist(N + 1, -1);
    queue<ll> que;

    dist[1] = 0;
    que.push(1);
    ll min_cycle_length = numeric_limits<ll>::max();
    while (!que.empty()){
        ll v = que.front();
        que.pop();

        for (ll nv : G[v]){
            if(nv == 1){
                cout << dist[v] + 1 << endl;
                return 0;
            }
            if (dist[nv] == -1){
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
