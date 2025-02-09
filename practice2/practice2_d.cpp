#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
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
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];

    mf_graph<int> g(n*m + 2);
    int s = n*m;
    int t = n*m + 1;

    auto index = [&](int i, int j) -> int { return i*m + j; };

    rep(i, n){
        rep(j, m){
            if((i+j)%2 == 0){
                rep(dir, 4){
                    int i2 = i + dx[dir], j2 = j + dy[dir];
                    if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= m) continue;
                    if(grid[i][j] == '.' && grid[i2][j2] == '.'){
                        g.add_edge(index(i, j), index(i2, j2), 1);
                    }
                }
            }

            if((i+j)%2 == 0 && grid[i][j] == '.'){
                g.add_edge(s, index(i, j), 1);
            }

            if((i+j)%2 == 1 && grid[i][j] == '.'){
                g.add_edge(index(i, j), t, 1);
            }

        }
    }

    int max_flow =  g.flow(s, t);
    
    const auto &edges = g.edges();
    for(auto &e : edges){
        if(e.from == s || e.to == t || e.flow == 0) continue;
        int ifrom = e.from/m, jfrom = e.from%m;
        int ito = e.to/m, jto = e.to%m;

        if(ifrom == ito){
            if(jfrom > jto) swap(jfrom, jto);
            grid[ifrom][jfrom] = '>';
            grid[ito][jto] = '<';
        }else{
            if(ifrom > ito) swap(ifrom, ito);
            grid[ifrom][jfrom] = 'v';
            grid[ito][jto] = '^';
        }
    }

    cout << max_flow << endl;
    rep(i, n) cout << grid[i] << endl;

}