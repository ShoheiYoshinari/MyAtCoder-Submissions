#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
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

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    map<ll, ll> mp;
    vector<ll> s(n+1, 0);
    rep(i, 1, n+1) s[i] = s[i-1] + a[i];
    rep(i, n+1) mp[s[i]]++;

    ll cnt = 0;
    for(auto p : mp){
        
        cnt += p.second*(p.second-1)/2;
    }
    cout << cnt << endl;
    return 0;
}