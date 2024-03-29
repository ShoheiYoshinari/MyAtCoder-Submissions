#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using Graph = vector<vector<int>>;

int dfs(Graph e, int v){
    int n = e.size();
    vector<int> dist(n, -1);

    dist[v] = 0;
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto nx : e[x]){
            if(dist[nx] == -1){
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }
    return *max_element(dist.begin(), dist.end());
}
int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    Graph e(n1 + n2);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int n1max = dfs(e, 0);
    int n2max = dfs(e, n1 + n2 -1);
    cout << n1max + n2max + 1 << endl;
}