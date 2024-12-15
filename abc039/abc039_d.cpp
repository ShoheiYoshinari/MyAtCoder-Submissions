#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w)), ans(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];

    vector<vector<bool>> is_seen(h, vector<bool>(w, false));
    rep(i, h){
        rep(j, w){
            bool is_black = (s[i][j] == '#' ? true : false);
            rep(dir, 8){
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if(s[ni][nj] == '.') is_black = false;
            }
            if(is_black){
                is_seen[i][j] = true;
                rep(dir, 8){
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    if(s[ni][nj] == '#') is_seen[ni][nj] = true;
                }
                ans[i][j] = '#';
            }else{
                ans[i][j] = '.';
            }
        }
    }

    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#') if(is_seen[i][j] == false){
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    rep(i, h){
        rep(j, w) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}