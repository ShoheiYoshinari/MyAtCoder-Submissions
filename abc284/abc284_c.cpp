#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; //v を訪問済みにする
    //v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 移動先が訪問済みならスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n+1);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--; // 配列の０番目に合わせる
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cnt = 0;
    seen.assign(n, false);
    for (int v = 0; v < n; v++) {
        if(seen[v] == true) continue;
        dfs(g, v);
        cnt++;
    }
    cout << cnt << endl;
}