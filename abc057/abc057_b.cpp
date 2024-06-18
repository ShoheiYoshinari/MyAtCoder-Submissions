#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<ll> c(m), d(m);
    rep(i, m) cin >> c[i] >> d[i];

    rep(i, n){
        ll dist_min = 1e18;
        ll pos = 0;
        rep(j, m){
            ll res = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(dist_min > res){
                dist_min = res;
                pos = j+1;
            }
        }
        cout << pos << endl;
    }
    return 0;
}