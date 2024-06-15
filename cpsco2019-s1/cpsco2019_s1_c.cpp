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
    int n, k;
    cin >> n>> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dig(n, 0);
    rep(i, k) dig[i] = 1;
    
    sort(all(dig));

    ll ans = 1e9;
    do{
        ll sum = 0;
        ll res = 0;
        rep(i, n){
            if(dig[i]) sum += a[i];
        }

        string sum_str = to_string(sum);
        rep(i, sum_str.size()){
            if(sum_str[i] >= '5') res += (int)(sum_str[i]-'5') + 1;
            else res += (int)(sum_str[i]-'0');
        }
        chmin(ans, res);
    }while(next_permutation(all(dig)));
    
    cout << ans << endl;
    return 0;
}