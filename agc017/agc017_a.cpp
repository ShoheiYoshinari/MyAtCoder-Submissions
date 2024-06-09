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

long long combi(long long n, long long k) {
  if (n == k || k == 0)
    return 1;
  else {
    return combi(n - 1, k - 1) + combi(n - 1, k);
  }
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int even = 0, odd = 0;
    rep(i, n){
        if(a[i]%2 == 0) even++;
        else odd++;
    }

    ll combi_even = 1ll << (even);
    ll cnt = 0;
    if(p == 1){
        for(int r = 1; r <= odd; r+=2){
            cnt += combi(odd, r)*combi_even;
        }
    }else if(p == 0){
        for(int r = 0; r <= odd; r+=2){
            cnt += combi(odd, r)*combi_even;
        }
    }
    cout << cnt << endl;
    return 0;
}