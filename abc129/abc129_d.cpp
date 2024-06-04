#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    vector<vector<int>> l(h, vector<int> (w, 0)), r(h, vector<int> (w, 0)), u(h, vector<int> (w, 0)), d(h, vector<int> (w, 0)); 
    rep(i, h) cin >> s[i];

    //left, up 
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        if(u[i][j] == 0) u[i][j] = 1;
        if(l[i][j] == 0) l[i][j] = 1;
        if(i) u[i][j] = u[i-1][j] + 1;
        if(j) l[i][j] = l[i][j-1] + 1;
    }
    //right, down
    for(int i = h-1; i >= 0; i--) for(int j = w-1; j >= 0; j--){
        if(s[i][j] == '#') continue;
        if(d[i][j] == 0) d[i][j] = 1;
        if(r[i][j] == 0) r[i][j] = 1;
        if(i != h-1) d[i][j] = d[i+1][j] + 1;
        if(j != w-1) r[i][j] = r[i][j+1] + 1; 
    }
    int ans = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '.'){
                chmax(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
            }
        }
    }
    cout << ans << endl;
    return 0;
}