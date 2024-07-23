#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a, T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a, T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

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

using mint = modint<1000000007>;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

mint lcm(mint a, ll b) {
    return a / gcd(a.value(), b) * b;
}

map<ll, ll> mp;

void prime_fact(ll n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ll cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            chmax(mp[i], cnt);
        }
    }
    if(n != 1) chmax(mp[n], 1ll);
    return;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n) prime_fact(a[i]);

    mint l = 1;
    for(auto p : mp) {
        rep(i, p.second) {
            l *= p.first;
        }
    }

    mint ans = 0;
    rep(i, n) {
        mint b = l / mint(a[i]);
        ans += b;
    }
    cout << ans << endl;
    return 0;
}
