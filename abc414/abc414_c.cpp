#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

struct INIT{
    INIT(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
}INIT;

string long_to_base9(long long n, long long p){
    string ans;
    while(n>0){
        char c = (char)((n%p)+'0');
        ans = c + ans;
        n /= p;
    }
    return ans;
}
bool is_palindrome(const string& s){
    int n = s.size();
    rep(i, n/2){
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

set<ll> palindromes(ll N){
    set<ll> res;
    for(int len = 1; len <= 12; len++){
        ll half = 1;
        rep(j, (len+1)/2) half *= 10ll;
        for(ll i = 1; i < half; ++i){
            string s = to_string(i);
            string rev = s;
            reverse(all(rev));
            string full;
            if(len%2 == 0){
                full = s + rev;
            } else {
                full = s + rev.substr(1);
            }
            ll val = stoll(full);
            if(val > N) break;
            res.insert(val);
        }
    }

    return res;
}

int main(){
    ll a, n;
    cin >> a >> n;

    ll ans = 0;
    set<ll> candidates = palindromes(n);

    for(ll x : candidates){
        string base_a = long_to_base9(x, a);
        if(is_palindrome(base_a)){
            ans += x;
        }
    }

    cout << ans << endl;
    return 0;
}
