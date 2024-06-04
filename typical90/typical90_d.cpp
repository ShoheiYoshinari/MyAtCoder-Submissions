#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
    vector<vector<int>> a(h+1, vector<int> (w+1, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(i, h) rep(j, w){
        a[i][w] += a[i][j];
        a[h][j] += a[i][j];
    }

    rep(i, h){
        rep(j, w){
        cout << a[i][w] + a[h][j] - a[i][j] << ' ';
        }
        cout << endl;
    }


}