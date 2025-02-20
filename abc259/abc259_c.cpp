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

vector<pair<char, int>> run_length_encoding(string s){
    vector<pair<char, int>> res;
    int idx = 0;
    while(idx < (int)(s.size())){
        char c = s[idx];
        int cnt = 1;
        while(c == s[idx+1]){
            idx++;
            cnt++;
        }
        res.push_back({c, cnt});
        idx++;
    }
    return res;
}

int main(){
    string s, t;
    cin >> s >> t;

    vector<pair<char,int>> s_comp, t_comp;
    s_comp = run_length_encoding(s);
    t_comp = run_length_encoding(t);

    if(s_comp.size() != t_comp.size()){
        cout << "No" << endl;
        return 0;
    }

    bool ok = true;
    rep(i, s_comp.size()){
        if(s_comp[i].first != t_comp[i].first) ok = false;
        if(!(s_comp[i].second == t_comp[i].second
        || s_comp[i].second < t_comp[i].second && s_comp[i].second >= 2)) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
