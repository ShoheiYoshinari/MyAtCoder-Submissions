#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

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
    vector<vector<int>> a(m);
    vector<vector<int>> pos(n);
    rep(i, m){
        int k; cin >> k;
        a[i].resize(k);
        rep(j, k){
            cin >> a[i][j];
            a[i][j]--;
            pos[a[i][j]].push_back(i);
        }
    }
    
    vector<int> cnt(n);
    queue<int> q;
    rep(i, m){
        int t = a[i].back();
        cnt[t]++;
    }

    rep(i, n) if(cnt[i] == 2) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        rep(i, 2){
            int p = pos[x][i];
            a[p].pop_back();
            if(a[p].size()){
                int t = a[p].back();
                cnt[t]++;
                if(cnt[t] == 2) q.push(t);
            }
        }
    }

    rep(i, m) if(a[i].size() != 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}