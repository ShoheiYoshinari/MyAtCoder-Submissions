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
    ll sum = 0;
    vector<ll> a(n*2);
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    //cout << sum << endl;
    rep(i, n) a[n+i] = a[i];

    bool isok = false;
    if(sum%10 != 0){
        cout << "No" << endl;
        return 0;
    }
    ll w10 = sum/10;
    ll res = 0;
    ll pos_back = 0;
    rep(i, n*2){
        //cout << res << endl;
        res += a[i];
        while(true){
            if(res > w10){
                res -= a[pos_back];
                pos_back++;
            }else break;
        }
        if(res == w10){
            isok = true;
            break;
        }
    }
    cout << (isok ? "Yes" : "No") << endl;
    return 0;
}