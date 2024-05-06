#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int r, c, sy, sx, gy, gx;
int main(){
    cin >> r >> c;
    cin >> sy >> sx;
    sy--; sx--;
    cin >> gy >> gx;
    gy--; gx--;
    
    char s[r][c];
    rep(i, r){
        rep(j, c) cin >> s[i][j];
    }

    queue<pair<int, int> > que;
    vector<vector<int> > dist(r, vector<int> (c, -1));

    dist[sy][sx] = 0;
    que.emplace(sy, sx);

    while(!que.empty()){
        auto [i, j]  = que.front(); que.pop();

        rep(v, 4){
            int ny = i + di[v];
            int nx = j + dj[v];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(dist[ny][nx] != -1) continue;
            if(s[ny][nx] != '.') continue;

            dist[ny][nx] = dist[i][j] + 1;
            que.emplace(ny, nx);
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}