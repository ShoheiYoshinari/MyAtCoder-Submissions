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

ll n;
ll h[1<<18], s[1<<18];

bool solved(ll mid){
    vector<long double> timer(n);
    rep(i, n){
        timer[i] = ((long double)(mid - h[i])/s[i]);
        //cout << timer[i] << ' ';
    }
    //cout << endl;
    sort(all(timer));
    bool isok = true;
    rep(i, n){
        if(i > timer[i]) isok = false;
    }
    if(isok) return true;
    else return false;
}

int main(){
    cin >> n;
    rep(i, n) cin >> h[i] >> s[i];

    ll left =  n;
    ll right = 1e18;

    while(right - left > 1){
        ll mid = left + (right-left)/2;

        if(solved(mid) == false) left = mid;
        else right = mid;
    }
    cout << right << endl;
    return 0;
}