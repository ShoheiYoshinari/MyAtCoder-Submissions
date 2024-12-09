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

pair<int, int> query(const vector<tuple<int, int, char, int>>& prdb){
    cout << prdb.size() << endl;
    for(const auto& [p, r ,d, b] : prdb){
        cout << p << ' ' << r << ' ' << d << ' ' << b << endl;
    }
    int w, h;
    cin >> w >> h;
    return {w, h};
}

int main(){
    int N, T, sigma;
    cin >> N >> T >> sigma;
    vector<pair<int, int>> wh(N);
    rep(i, N){
        cin >> wh[i].first >> wh[i].second;
    }

    mt19937 rng(12345);
    uniform_int_distribution<int> rand01(0, 1);
    uniform_int_distribution<int> randChar(0, 1);
    rep(t ,T){
        vector<tuple<int, int, char, int>> prdb;
        rep(i, N){
            int r = rand01(rng);
            char d = randChar(rng) == 0 ? 'U' : 'L';
            uniform_int_distribution<int> randB(-1, i - 1); // -1からi-1までの値を生成
            int b = randB(rng);
            prdb.emplace_back(i, r, d, b);
        }
        query(prdb);
    }
}