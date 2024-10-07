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
int main() {
	int n;
	cin >> n;
	vector<int> q(n), a(n), b(n);
	rep(i, n) cin >> q[i];
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	int ans = 0;
	for(int x = 0;; x++){
		vector<int> r(n);
		rep(i, n) r[i] = q[i] - a[i]*x;
		bool ok = true;
		rep(i, n) if(r[i] < 0) ok = false;
		if(!ok) break;

		int y = 1e9;
		rep(i, n){
			if(b[i] == 0) continue;
			y = min(y, r[i]/b[i]);
		}
		ans = max(ans, x+y);
	}
	cout << ans << endl;
	return 0;
}