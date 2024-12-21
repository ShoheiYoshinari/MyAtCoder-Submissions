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
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main(){
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    string t;
    cin >> t;

    set<pair<int, int>> st;
    st.insert({x, y});

    int cnt = 0;
    rep(i, t.size()) {
        int nx = x, ny = y;
        if (t[i] == 'U') nx = x-1, ny = y;
        if (t[i] == 'D') nx = x+1, ny = y;
        if (t[i] == 'L') nx = x, ny = y-1;
        if (t[i] == 'R') nx = x, ny = y+1;
        if (s[nx-1][ny-1] != '#') {
            x = nx, y = ny;
            if (s[x-1][y-1] == '@') {
                if (!st.count({x, y})) {
                    cnt++;
                }
            }
            st.insert({x, y});
        }
    }
    cout << x << ' ' << y << ' ' << cnt << endl;
}