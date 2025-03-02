#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
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
    int h1, w1, h2, w2;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    rep(i, h1) rep(j, w1) cin >> a[i][j];
    cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    vector<int> row, col;
    rep(i, h1-h2) row.push_back(0);
    rep(i, h2) row.push_back(1);
    rep(i, w1-w2) col.push_back(0);
    rep(i, w2) col.push_back(1);

    do{
        do{
            bool ok = true;
            int row_cnt = 0;
            int col_cnt = 0;
            rep(i, row.size()){
                col_cnt = 0;
                rep(j, col.size()){
                    if(row[i] == 1 && col[j] == 1){
                        if(a[i][j] != b[row_cnt][col_cnt]){
                            ok = false;
                        }
                        col_cnt++;
                    }
                }
                if(row[i]) row_cnt++;
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }while(next_permutation(all(col)));
    }while(next_permutation(all(row)));
    cout << "No" << endl;
    return 0;
}