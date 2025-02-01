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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> r(n);
    rep(i, n){
        int a; cin >> a;
        rep(j, a){
            int x, y;
            cin >> x >> y;
            x--;
            r[i].push_back({x, y});
        }
    }

    int ans = -1;
    rep(i, 1<<n){
        vector<int> honest;
        rep(j, n){
            if(i&(1<<j)) honest.push_back(j);
        }

        bool ok = true;
        for(auto& h : honest){
            rep(k, r[h].size()){
                if(r[h][k].second == 1){
                    if(find(all(honest), r[h][k].first) == honest.end()) ok = false;
                }else{
                    if(find(all(honest), r[h][k].first) != honest.end()) ok = false;
                }
            }
        }
        if(ok) chmax(ans, (int)honest.size());
    }
    cout << ans << endl;
    return 0;
}