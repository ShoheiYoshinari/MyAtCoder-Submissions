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
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

bool is_possi(int n, string s){
    int mask = (1<<n)-1;
    vector<bool> denger(mask+1, false);
    for(int i = 1; i <= mask; i++){ 
        if(s[i-1] == '1') denger[i] = true;
    }

    vector<bool> visited(mask+1, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int m = q.front(); q.pop();
        rep(i, n){
            if(!(m & (1<<i))){
                int nx = m | (1<<i);
                if(!denger[nx] && !visited[nx]){
                    visited[nx] = true;
                    q.push(nx);
                }
            }
        }
    }
    return visited[mask];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;
        cout << (is_possi(n, s) ? "Yes" : "No") << endl;
    }

}