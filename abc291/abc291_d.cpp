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

//modint copy
template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;
public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
	constexpr u64 &value() noexcept { return a; }
	constexpr const u64 &value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
    	return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	constexpr modint &operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
    	return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept {
    	a = a * rhs.a % Modulus;
    	return *this;
	}
	constexpr modint &operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
    	return *this;
	}

    friend std::ostream& operator<<(std::ostream& os, const modint& rhs) {
        os << rhs.a;
        return os;
    }
};
using mint = modint<998244353>;

int main(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
    }
    
    vector<vector<mint>> dp(n+1, vector<mint> (2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i, 1, n){
        if(a[i] != a[i-1]) dp[i][0] += dp[i-1][0];
        if(a[i] != b[i-1]) dp[i][0] += dp[i-1][1];
        if(b[i] != a[i-1]) dp[i][1] += dp[i-1][0];
        if(b[i] != b[i-1]) dp[i][1] += dp[i-1][1];  
        //cout << dp[i][0] <<' '<< dp[i][1] << endl;
    }
    mint ans = dp[n-1][0] + dp[n-1][1];
    cout << ans << endl;
    return 0;

}