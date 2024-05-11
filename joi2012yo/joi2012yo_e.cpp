#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()

int dx[2][6] = {
    {1, 0, -1, 0, 1, -1},
    {1, 0, -1, 0, 1, -1}
};
int dy[2][6] = {
    {0, 1, 0, -1, -1, -1},
    {0, 1, 0, -1, 1, 1}
};

int main(){
    int w, h;
    cin >> w >> h;
    vector<vector<int> > fi(h+2, vector<int>(w+2, 0));
    rep2(i, 1, h){
        rep2(j, 1, w) cin >> fi[i][j]; 
    }
    vector<vector<bool> > seen(h+2, vector<bool>(w+2, false));

    auto bfs = [&](auto self, int x, int y) -> void {
        seen[x][y] = true;
        rep(dir, 6){
            int nx = x + dx[x%2][dir], ny = y + dy[x%2][dir];
            if(nx < 0 || nx >= h+2 || ny < 0 || ny >= w+2) continue;
            if(fi[x][y] == 1) continue;
            if(!seen[nx][ny]) self(self, nx, ny);
        }
    };

    bfs(bfs, 0, 0);
    rep2(x, 1, h) rep2(y, 1, w) if(!seen[x][y]) fi[x][y] = 1;
    int cnt = 0;
    rep2(x, 1, h){
        rep2(y, 1, w){
            if(fi[x][y] == 0) continue;
            //建物の周囲6方向を探索、空間なら＋１
            rep(dir, 6){
                int nx = x + dx[x%2][dir], ny = y + dy[x%2][dir];
                if(fi[nx][ny] == 0) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}