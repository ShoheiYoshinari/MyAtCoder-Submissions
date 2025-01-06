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

ll sum_pow(ll a, ll r){
    ll res = 1;
    for(ll i = 1; i <= r; i++) res *= a;
    return res;
}


ll count(ll r){
    vector<ll> digit;
    while(r){
        digit.push_back(r%10);
        r /= 10;
    }
    reverse(all(digit));

    ll k = digit.size();
    ll res = 0;
    //k未満
    for(ll i = 0; i < k; i++){
        int mx = (i ? 9 : digit[0]-1);
        for(ll j = 1; j <= mx; j++){
            res += sum_pow(j, k-1-i);
        }
    }

    //k
    for(ll i = 1; i <= k; i++){
        if(i == k){
            res++;
            break;
        }
        for(ll j = 0; j < min(digit[0], digit[i]); j++){
            res += sum_pow(digit[0], k-1-i);
        }
        if(digit[i] >= digit[0]) break;
    }
    return res;
}

int main(){
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l-1) << endl;
}