#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int h, w, q;
UnionFind uf;
bool used[2009][2009];

void query1(int x, int y){
    rep(i, 4){
        int sx = x + dx[i];
        int sy = y + dy[i];
        if(used[sx][sy] == false) continue;
        int hash1 = (sx-1)*w+(sy-1);
        int hash2 = (x-1)*w+(y-1);
        uf.unite(hash1, hash2);
    }
    used[x][y] = true;
}

bool query2(int px, int py, int qx, int qy){
    if(used[px][py] == false || used[qx][qy] == false){
        return false;
    }
    int hash1 = (px-1)*w+(py-1);
    int hash2 = (qx-1)*w+(qy-1);
    if(uf.same(hash1, hash2) == true) return true;
    else return false;
}

int main() {
    cin >> h >> w >> q;
    uf.init(h*w);

    rep(i, q){
        int ty; cin >> ty;
        if(ty == 1){
            int x, y;
            cin >> x >> y;
            query1(x, y);
        }else if(ty == 2){
            int xa, xb, ya, yb;
            cin >> xa >> xb >> ya >> yb;
            bool ans = query2(xa, xb, ya, yb);
            cout << (ans ? "Yes" : "No") << endl;
        }
    }
     
}