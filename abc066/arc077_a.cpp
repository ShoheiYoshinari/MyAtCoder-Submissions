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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    bool inv = true;
    deque<int> deq;
    rep(i, n){
        if(inv) deq.push_back(a[i]);
        else deq.push_front(a[i]);
        inv = !inv;
    }

    if(!inv){
        for(auto itr = deq.rbegin(); itr != deq.rend(); ++itr){
            cout << *itr << ' ';
        }
        cout << endl;
    }else{
        for(auto itr = deq.begin(); itr != deq.end(); ++itr){
            cout << *itr << ' ';
        }
        cout << endl;
    }
    return 0;
}