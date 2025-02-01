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

long double distance(ll ax, ll ay, ll bx, ll by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n+1), y(n+1);
    rep(i, 1, n+1) cin >> x[i] >> y[i];

    vector<int> p(n+1);
    vector<bool> seen(n+1, false);

    int nowPlace = 1;
    p[1] = 1;
    seen[1] = true;
    for(int i = 2; i <= n; i++){
        long double minDist = 10000.0;
        int minID = -1;

        for(int j = 1; j <= n; j++){
            if(seen[j] == true) continue;
            long double newDist = distance(x[nowPlace], y[nowPlace], x[j], y[j]);
            if(minDist > newDist){
                minDist = newDist;
                minID = j;
            }
        }
        seen[minID] = true;
        p[i] = minID;
        nowPlace = minID;
    }
    p[n+1] = 1;

    rep(i, 1, n+2){
        cout << p[i] << endl;
    }
    return 0;
}