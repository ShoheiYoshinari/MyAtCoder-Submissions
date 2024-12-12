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

long double distance(ll ax, ll ay, ll bx, ll by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main(){
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    vector<pair<ll, ll>> p;
    p.push_back({sx-1, sy+2});
    p.push_back({sx-1, sy-2});
    p.push_back({sx-2, sy+1});
    p.push_back({sx-2, sy-1});
    p.push_back({sx+1, sy-2});
    p.push_back({sx+1, sy+2});
    p.push_back({sx+2, sy-1});
    p.push_back({sx+2, sy+1});

    rep(i, p.size()){
        if(distance(p[i].first, p[i].second, gx, gy) == (long double)(sqrt(5))){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}