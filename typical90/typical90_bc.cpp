#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
    ll n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll cnt = 0;
    rep2(i, 0, n){
        rep2(j, i+1, n){
            rep2(k, j+1, n){
                rep2(l, k+1, n){
                    rep2(m, l+1, n){
                        if(a[i]%p*a[j]%p*a[k]%p*a[l]%p*a[m]%p == q) cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}