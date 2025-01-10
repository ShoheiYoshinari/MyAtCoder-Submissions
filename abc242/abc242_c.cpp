
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
    ll n;
    cin >> n;
    vector<vector<mint>> dp(n, vector<mint>(10, 0));

    rep(i, 1, 10) dp[0][i] = 1;
    rep(i, 1, n){
        rep(j, 1, 10){
            if(j == 1){
                dp[i][j] += dp[i-1][1] + dp[i-1][2];
            }else if(j == 9){
                dp[i][j] += dp[i-1][8] + dp[i-1][9];
            }else{
                dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    mint ans = 0;
    rep(i, 1, 10) ans += dp[n-1][i];
    cout << ans << endl;

}