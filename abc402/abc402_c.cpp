#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ing(m), used(n+1);
    rep(i, m){
        int k;
        cin >> k;
        ing[i].resize(k);
        rep(j, k){
            cin >> ing[i][j];
            used[ing[i][j]].push_back(i);
        }
    }

    vector<int> b(n);
    rep(i, n) cin >> b[i];

    vector<int> cnt(m);
    rep(i, m) cnt[i] = ing[i].size();

    vector<bool> eat(m, false);
    int ans = 0;
    rep(i, n){
        int x = b[i];
        for(auto d : used[x]){
            cnt[d]--;
            if(cnt[d] == 0){
                ans++;
                eat[d] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}