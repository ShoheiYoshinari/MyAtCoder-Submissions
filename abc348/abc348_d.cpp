#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

using P = pair<int, int>;

struct Med
{
    int r, c, e;
    Med() {}
    Med(int r, int c, int e): r(r), c(c), e(e) {}
};


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int si = 0, sj = 0, ti = 0, tj = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == 'S') si = i, sj = j;
            if(s[i][j] == 'T') ti = i, tj = j;
        }
    }

    int n;
    cin >> n;
    vector<Med> meds(n);
    rep(i, n){
        int r, c, e;
        cin >> r >> c >> e;
        r--, c--;
        meds[i] = Med(r, c, e);
    }
    n += 2;
    meds.emplace_back(si, sj, 0);
    meds.emplace_back(ti, tj, 0);
    int smi = n-2, tmi = n-1;


    const int INF = 1001001001;

    vector<vector<int> > to(n);
    rep(sv, n){
        auto [sr, sc, se] = meds[sv];
        vector dist(h, vector<int>(w, INF));
        queue<P> q;
        dist[sr][sc] = 0; q.emplace(sr, sc);
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            rep(dir, 4){
                int ni = i+di[dir], nj = j+dj[dir];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(dist[ni][nj] != INF) continue;
                if(s[ni][nj] == '#') continue;
                dist[ni][nj] = dist[i][j] + 1;
                q.emplace(ni, nj);
            }
        }

        rep(v, n){
            if(sv != v){
                auto [r, c, e] = meds[v];
                if(dist[r][c] <= se) to[sv].push_back(v);
            }
        }
    }

    vector<int> dist(n, INF);
    queue<int> q;
    dist[smi] = 0; q.push(smi);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int u : to[v]){
            if(dist[u] != INF) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    if(dist[tmi] != INF) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
