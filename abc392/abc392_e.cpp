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

struct UnionFind {
    // core member
    vector<int> par;

    // constructor
    UnionFind() { }
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    // core methods
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
    
    // グループ構造の詳細を取得する関数
    vector<vector<int>> groups() {
        // member[v] := 要素 v をリーダーとするグループ
        vector<vector<int>> member(par.size());
        for (int v = 0; v < (int)par.size(); ++v) {
            member[root(v)].push_back(v);
        }
        
        // 配列 member の空の部分を削除したものを作る
        vector<vector<int>> res;
        for (int v = 0; v < (int)par.size(); ++v) {
            if (!member[v].empty()) res.push_back(member[v]);
        }
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    vector<tuple<int, int, int>> es;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(uf.same(a, b)){
            es.push_back({i, a, b});
        }else{
            uf.unite(a, b);
        }
    }

    set<int> st;
    rep(i, n) st.insert(uf.root(i));
    cout << st.size()-1 << endl;
    while(st.size() > 1){
        auto [ei, a, b] = es.back(); es.pop_back();
        int v = uf.root(a);
        st.erase(v);
        int u = *st.begin();
        st.erase(u);
        uf.unite(u, v);
        st.insert(uf.root(v));
        cout << ei+1 << ' ' << a+1 << ' ' << u+1 << endl;
    }
}