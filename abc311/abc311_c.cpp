#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using Graph = vector<vector<int>>;
int main() {
    int n;
    cin >> n;
    Graph G(n);

    rep(i, n){
        int a;
        cin >> a;
        a--;
        G[i].push_back(a);
    }

    int cnt = 0;

    // BFS のためのデータ構造
    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    vector<int> found;
    queue<int> que;
    // 初期条件 (頂点 0 を初期ノードとする)
    found.push_back(0);
    dist[0] = 0;
    cnt++;
    que.push(0); // 0 を橙色頂点にする
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {

            if (dist[nv] != -1){
                cout << dist[v] - dist[nv] + 1 << endl;
                bool ans = false;
                for(int i = 0; i < found.size(); i++){
                    if(found[i] == nv) ans = true;
                    if(ans){
                        cout << found[i] + 1 << ' ';
                    }
                }
                cout << endl;
                return 0;
            }
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = cnt;
            cnt++;
            found.push_back(nv);
            que.push(nv);
        }
    }
}