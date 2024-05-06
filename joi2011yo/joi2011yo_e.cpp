#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int h, w, n;
int main(){
    cin >> h >> w >> n;
    
    char s[h][w];
    vector<vector<int> > dist(h, vector<int> (w, -1));
    vector<pair<int, int> > path(n+1);
    queue<pair<int, int> > que;

    rep(i, h){
        rep(j, w){
            cin >> s[i][j];
            if((int)(s[i][j] - '0') >= 1 && (int)(s[i][j] - '0') <= n){
                path[(int)(s[i][j] - '0')].first = i;
                path[(int)(s[i][j] - '0')].second = j;
            }
            if(s[i][j] == 'S'){
                dist[i][j] = 0;
                que.emplace(i, j);
            }
        }
    }

    int sum = 0;

    rep(k, n){
        if(k > 0){
            dist[path[k].first][path[k].second] = 0;
            que.emplace(path[k].first, path[k].second);
        }
        while(!que.empty()){
            auto [i, j]  = que.front(); que.pop();

            rep(v, 4){
                int ny = i + di[v];
                int nx = j + dj[v];
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(dist[ny][nx] != -1) continue;
                if(s[ny][nx] == 'X') continue;

                dist[ny][nx] = dist[i][j] + 1;
                que.emplace(ny, nx);
            }
        }
        sum += dist[path[k+1].first][path[k+1].second];
        rep(i, h) rep(j, w) dist[i][j] = -1;
    }

    cout << sum << endl;
    return 0;
}