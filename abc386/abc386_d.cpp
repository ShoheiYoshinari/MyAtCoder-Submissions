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
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, char>>> tate, yoko;
    rep(i, m){
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--, y--;
        tate[x].push_back({y, c});
        yoko[y].push_back({x, c});
    }

    int mn_w = n;
    for(auto& [y, v] : tate){
        sort(all(v));
        for(auto& [y, c] : v){
            if(c == 'W') chmin(mn_w, y);
            else if(y >= mn_w){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    mn_w = n;
    for(auto& [x, v] : yoko){
        sort(all(v));
        for(auto& [x, c] : v){
            if(c == 'W') chmin(mn_w, x);
            else if(x >= mn_w){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}