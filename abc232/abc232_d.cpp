#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int dx[] = {1, 0}; // 右と下の移動
const int dy[] = {0, 1}; // 右と下の移動

int h, w;

void BFS(const vector<vector<char>> &c, vector<vector<ll>> &dist) {
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0][0] = 1;
    while (!que.empty()) {
        auto [vx, vy] = que.front();
        que.pop();
        for (int i = 0; i < 2; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; // 範囲外チェック
            if (c[nx][ny] == '#') continue; // 壁チェック
            if (dist[nx][ny] != -1) continue; // 訪問済みチェック
            dist[nx][ny] = dist[vx][vy] + 1;
            que.push({nx, ny});
        }
    }
}

int main() {
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c[i][j];
        }
    }

    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    BFS(c, dist);

    ll max_dist = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (dist[i][j] != -1) {
                max_dist = max(max_dist, dist[i][j]);
            }
        }
    }

    cout << max_dist << endl;
    return 0;
}
