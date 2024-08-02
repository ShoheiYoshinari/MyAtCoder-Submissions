#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) < (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) < (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
    int h, w, y, x;
    cin >> h >> w >> y >> x;
    y--, x--;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    string s;
    cin >> s;

    string direction = "DRUL";
    rep(i, s.size()){
        rep(dir, 4){
            if(s[i] == direction[dir]){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if(c[ny][nx] == '#') continue;
                
                x = nx; 
                y = ny;
            }
        }
    }
    cout << y+1 << ' ' << x+1 << endl;
    return 0;
}