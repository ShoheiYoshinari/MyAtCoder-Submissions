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
    int n;
    cin >> n;
    vector<pair<int, int>> c;
    rep(i, n){
        int cc, p;
        cin >> cc >> p;
        c.emplace_back(cc, p);
    }

    vector<vector<int>> s(3, vector<int> (n+1, 0));
    rep(i, n){
        if(c[i].first == 1){
            s[1][i+1] = s[1][i] + c[i].second;
            s[2][i+1] = s[2][i];
        }else if(c[i].first == 2){
            s[1][i+1] = s[1][i];
            s[2][i+1] = s[2][i] + c[i].second;
        }
    }

    int q;
    cin >> q;
    rep(i, q){
        int l, r;
        cin >> l >> r;
        cout << s[1][r] - s[1][l-1] << ' ' << s[2][r] - s[2][l-1] << endl;
    }
}