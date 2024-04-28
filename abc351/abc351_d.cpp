#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    // x：磁石の位置をtrueに
    vector x(h, vector<bool>(w));
    rep(i, h)rep(j, w) if(s[i][j] == '#'){
        x[i][j] = true;
        rep(v, 4){
            int ni = i + di[v];
            int nj = j + dj[v];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            x[ni][nj] = true;
        }
    }

    // used：訪れたマスをtrueに
    vector used(h, vector<bool>(w));
    // last : ある位置からの探索でxを使っているかどうか
    vector last(h, vector<int>(w)); int tm = 0;
    int ans = 1;
    rep(si, h)rep(sj, w) if(!x[si][sj]){
        if(used[si][sj]) continue;
        tm++;
        int cnt = 0;
        queue<pair<int, int>> q;
        q.emplace(si, sj); used[si][sj] = true;
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            cnt++;
            rep(v, 4){
                int ni = i + di[v];
                int nj = j + dj[v];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if(used[ni][nj]) continue;
                // 磁石で動かない位置x　かつ　
                if(x[ni][nj]){
                    if(last[ni][nj] != tm) cnt++, last[ni][nj] = tm;
                    continue;
                }
                q.emplace(ni, nj); used[ni][nj] = true;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
