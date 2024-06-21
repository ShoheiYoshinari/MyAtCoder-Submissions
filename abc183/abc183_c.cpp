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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int> (n));
    rep(i, n) rep(j, n) cin >> t[i][j];

    vector<int> od(n-1);
    rep(i, n-1) od[i] = i+1;

    ll cnt = 0;
    ll time;
    int from;
    do{
        time = 0;
        from = 0;
        rep(i, od.size()){
            time += t[from][od[i]];
            from = od[i];
        }
        time += t[od.back()][0];
        if(time == k) cnt++;
    }while(next_permutation(all(od)));
    cout << cnt << endl;
    return 0;
}