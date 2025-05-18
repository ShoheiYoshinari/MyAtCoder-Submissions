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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> x(n), y(n);

    vector<vector<int>> row(h), col(w);
    vector<int> row_cnt(h), col_cnt(w);

    rep(i, n){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        row[x[i]].push_back(y[i]);
        col[y[i]].push_back(x[i]);
        row_cnt[x[i]]++;
        col_cnt[y[i]]++;
    }

    vector<bool> row_del(h), col_del(w);

    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            x--;

            if(row_del[x]){
                cout << 0 << endl;
            }else{
                cout << row_cnt[x] << endl;
                row_del[x] = true;
                for(auto y : row[x]){
                    if(!col_del[y]){
                        col_cnt[y]--;
                    }
                }
            }
        }else if(t == 2){
            int y;
            cin >> y;
            y--;

            if(col_del[y]){
                cout << 0 << endl;
            }else{
                cout << col_cnt[y] << endl;
                col_del[y] = true;
                for(auto x : col[y]){
                    if(!row_del[x]){
                        row_cnt[x]--;
                    }
                }
            }
        }
    }
    return 0;
}