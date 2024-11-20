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

long double distance(ll x, ll y, ll nx, ll ny){
    return sqrt((x-nx)*(x-nx) + (y-ny)*(y-ny));
}
int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pos;
    rep(i, n){
        ll x, y; cin >> x >> y;
        pos.push_back({x, y});
    }
    
    vector<int> p(n);
    rep(i, n) p[i] = i;

    long double dist = 0;
    long double sum = 0;
    ll cnt = 0;
    do{
        dist = 0;
        rep(i, n-1){
            dist += distance(pos[p[i]].first, pos[p[i]].second, pos[p[i+1]].first, pos[p[i+1]].second);
        }
        sum += dist;
        cnt++;
    }while(next_permutation(all(p)));
    cout << sum / (long double) cnt << endl;
    
}