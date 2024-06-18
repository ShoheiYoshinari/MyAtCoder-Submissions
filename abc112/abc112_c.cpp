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
    int n, idx;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    rep(i, n) cin >> x[i] >> y[i] >> h[i];
    rep(i, n) if(h[i] != 0) idx = i;

    rep(ix, 101){
        rep(iy, 101){
            bool ok = true;
            ll alti = h[idx]+abs(ix-x[idx])+abs(iy-y[idx]);
            if(alti < 0ll) continue;
            rep(i, n){
                if(h[i] != max(alti-abs(ix-x[i])-abs(iy-y[i]), 0ll)) ok = false;
            }
            if(ok){
                cout << ix << ' ' << iy << ' ' << alti << endl;
                return 0;
            }
        }
    }
}