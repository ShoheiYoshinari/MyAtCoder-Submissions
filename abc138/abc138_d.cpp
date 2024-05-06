#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, q, a, b ,pp, x;

vector<bool> seen;
map<int, int> p;
vector<int> point;
void dfs(const Graph &G, int v, int sum) {
    sum += p[v];
    point[v] = sum;
    seen[v] = true; //v を訪問済みにする
    //v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 移動先が訪問済みならスルー
        dfs(G, next_v, sum); // 再帰的に探索
    }
}

int main(){
    cin >> n >> q;

    Graph G(n);
    
    rep(i, n-1){
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, q){
        cin >> pp >> x;
        pp--;
        p[pp] += x;
    }
    seen.assign(n, false);
    point.assign(n, 0);
    dfs(G, 0, 0);
    rep(i, n){
        cout << point[i] << ' ';
    }
    cout << endl;
    return 0;
}
