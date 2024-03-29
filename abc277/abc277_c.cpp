#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
    using Graph = map<int, vector<int>>;
    int main() {
        // 辺数
        int M; cin >> M;
        // グラフ入力受取 (ここでは無向グラフを想定)
        Graph G;
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        // BFS のためのデータ構造
        queue<int> que;
        // 初期条件 (頂点 1 を初期ノードとする)
        que.push(1); // 1 を橙色頂点にする
        set<int> S;
        S.insert(1);
        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            int v = que.front(); // キューから先頭頂点を取り出す
            que.pop();
            // v から辿れる頂点をすべて調べる
            for (int nv : G[v]) {
                if (!S.count(nv)){ // 頂点nvがセットの要素にないとき
                // 新たな白色頂点 nv についてキューに追加してセットに追加
                que.push(nv);
                S.insert(nv);
            }
        }
        }
        // 結果出力
        cout << *S.rbegin() << endl;
    }