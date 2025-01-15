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

bool my_compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}

int judgment(char a, char b){
    if(a == b) return 1;
    else if((a == 'G' && b == 'C')||(a == 'C' && b == 'P')||(a == 'P' && b == 'G')) return 2;
    else return 3;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(2*n, vector<char>(m));
    rep(i, 2*n) rep(j, m) cin >> a[i][j];

    vector<pair<int, int>> p(2*n);
    rep(i, 2*n) p[i] = {0, i};

    rep(j, m){
        for(int i = 0; i < 2*n; i+=2){
            int tmp = judgment(a[p[i].second][j], a[p[i+1].second][j]);
            if(tmp == 2) p[i].first++;
            if(tmp == 3) p[i+1].first++;
        }
        sort(all(p), my_compare);
        // rep(i, 2*n) cout << p[i].first << ' ' << p[i].second + 1 << endl;
        // cout << endl;
    }

    rep(i, 2*n) cout << p[i].second + 1 << endl;
    return 0;
}