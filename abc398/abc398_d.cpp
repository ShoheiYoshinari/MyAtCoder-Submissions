#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for(auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for(auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T &a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> bool chmax(T &a, T b){ if(a < b){ a = b; return true; } return false; }
template<class T> constexpr T INF(){ return ::std::numeric_limits<T>::max(); }
template<class T> constexpr T HINF(){ return INF<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
struct INIT{ INIT(){ ios::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20); } }INIT;

int main(){
	int n, r, c;
	string s;
	cin >> n >> r >> c >> s;
	map<char, pair<int,int>> d = {
		{'N', {-1, 0}},
		{'W', {0, -1}},
		{'S', {1, 0}},
		{'E', {0, 1}}
	};
	vector<int> x(n+1, 0), y(n+1, 0);
	rep(i, n) {
		x[i+1] = x[i] + d[s[i]].first;
		y[i+1] = y[i] + d[s[i]].second;
	}
	map<pair<int,int>, int> mp;
	mp[{0,0}] = 0;
	rep(i, 1, n+1) {
		pair<int,int> p = {x[i], y[i]};
		if(!exists(mp, p)) mp[p] = i;
	}
	string ans(n, '0');
	for (int t = 1; t <= n; t++){
		int tx = x[t] - r, ty = y[t] - c;
		pair<int,int> p = {tx, ty};
		if(exists(mp, p) && mp[p] <= t) ans[t-1] = '1';
	}
	cout << ans << "\n";
	return 0;
}
