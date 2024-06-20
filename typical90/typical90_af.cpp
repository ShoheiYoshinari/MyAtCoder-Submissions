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
    int n, m;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    rep(i, n) rep(j, n){
        int aa; cin >> aa;
        a[i][j] = aa;
    }
    vector<vector<int>> bad(n, vector<int> (n, 0));
    cin >> m;
    rep(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        bad[x][y]++;
        bad[y][x]++;
    }

    vector<int> order(n);
    rep(i, n) order[i] = i;
    ll min_dist = 1e9;
    bool isok;
    ll res;
    do{
        res = 0;
        isok = true;
        for(int i = 0; i < n; i++){
            if(i != n-1) if(bad[order[i]][order[i+1]] != 0) isok = false;
            res += a[order[i]][i];
        }
        if(isok) chmin(min_dist, res);
    }while(next_permutation(all(order)));
    
    cout << (min_dist == 1e9 ? -1 : min_dist) << endl;
    return 0;
}