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

bool isPrime(ll x){
   int i;
   if(x < 2)return 0;
   else if(x == 2) return 1;
   if(x%2 == 0) return 0;
   for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
   return 1;
}

int main(){
    ll n; cin >> n;

    set<ll> st;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            st.insert(i);
            st.insert(n/i);
        }
    }
    for(auto& ans : st) cout << ans << endl;
    return 0;
}