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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(n), r(n);
    rep(i, q){
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }

    vector<int> sm(n+1, 0);
    rep(i, 1, n+1){
        if(s[i-1] == 'A' && s[i] == 'C'){
            sm[i] = sm[i-1] + 1;
        }else{
            sm[i] = sm[i-1];
        }
    }

    rep(i, q){
        cout << sm[r[i]] - sm[l[i]] << endl;
    }
    return 0;
}