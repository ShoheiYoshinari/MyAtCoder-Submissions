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
    vector<vector<char>> s(n, vector<char>(n)), t(m, vector<char>(m));
    rep(i, n) rep(j, n) cin >> s[i][j];
    rep(i, m) rep(j, m) cin >> t[i][j];

    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            bool ok = true;
            rep(k, m){
                rep(l, m){
                    if(s[i+k][j+l] != t[k][l]) ok = false;
                }
            }
            if(ok){
                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}