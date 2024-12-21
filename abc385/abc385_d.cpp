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

int main() {
    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    sx--, sy--;

    map<ll, set<ll>> x_house;
    map<ll, set<ll>> y_house;

    rep(i, n){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        x_house[x].insert(y);
        y_house[y].insert(x);
    }

    set<pair<ll, ll>> visited_house;
    visited_house.insert({sx, sy});

    ll x = sx, y = sy;
    rep(i, m){
        char d;
        ll c;
        cin >> d >> c;

        if (d == 'U'){
            ll new_y = y + c;
            auto itr1 = x_house[x].lower_bound(y + 1);
            auto itr2 = x_house[x].lower_bound(new_y + 1);
            for (auto itr = itr1; itr != itr2; ) {
                visited_house.insert({x, *itr});
                itr = x_house[x].erase(itr);
            }
            y = new_y;
        }else if(d == 'D'){
            ll new_y = y - c;
            auto itr1 = x_house[x].lower_bound(new_y);
            auto itr2 = x_house[x].lower_bound(y);
            for (auto itr = itr1; itr != itr2; ) {
                visited_house.insert({x, *itr});
                itr = x_house[x].erase(itr);
            }
            y = new_y;
        }else if(d == 'L'){
            ll new_x = x - c;
            auto itr1 = y_house[y].lower_bound(new_x);
            auto itr2 = y_house[y].lower_bound(x);
            for (auto itr = itr1; itr != itr2; ) {
                visited_house.insert({*itr, y});
                itr = y_house[y].erase(itr);
            }
            x = new_x;
        }else if (d == 'R'){
            ll new_x = x + c;
            auto itr1 = y_house[y].lower_bound(x + 1);
            auto itr2 = y_house[y].lower_bound(new_x + 1);
            for (auto itr = itr1; itr != itr2; ) {
                visited_house.insert({*itr, y});
                itr = y_house[y].erase(itr); 
            }
            x = new_x;
        }
    }

    cout << x + 1 << ' ' << y + 1 << ' ' << visited_house.size() - 1 << endl;

    return 0;
}