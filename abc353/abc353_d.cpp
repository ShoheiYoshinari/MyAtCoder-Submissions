#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(11, 0);
    rep(i, n){
        cin >> a[i];
        d[to_string(a[i]).size()]++;
    }

    vector<mint> keta(11, 1);
    rep2(i, 1, 10) keta[i] = keta[i-1] * 10;

    mint s = 0;
    rep2(i, 1, 10) s += keta[i] * d[i];

    mint ans = 0;
    rep(i, n){
        ans += mint(a[i]) * i;
        s -= keta[to_string(a[i]).size()];
        ans += s * a[i];
        //cout << ans << endl;
    }
    cout << ans << endl;

}