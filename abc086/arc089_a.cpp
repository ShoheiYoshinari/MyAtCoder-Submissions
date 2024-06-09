#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

#ifdef LOCAL
#  include "_debug_print.hpp"
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

int main(){
    ll n;
    cin >> n;
    vector<ll> t(n), x(n), y(n);
    rep(i, n) cin >> t[i] >> x[i] >> y[i];

    ll cx = 0, cy = 0;
    ll timer = 0;
    rep(i, n){
        ll res = t[i] - timer;
        ll dist = abs(cx-x[i]) + abs(cy-y[i]);

        if(dist > res || (res-dist)%2 == 1){
            cout << "No" << endl;
            return 0;
        }
        cx = x[i];
        cy = y[i];
        timer = t[i];
    }
    cout << "Yes" << endl;
    return 0;
}