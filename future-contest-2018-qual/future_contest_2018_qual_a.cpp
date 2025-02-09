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

int n = 100;
int q = 1000;
vector<vector<int>> a(n, vector<int> (n, 0)), b(n, vector<int> (n, 0));
vector<int> X(q), Y(q), H(q);

int RandInt(int l, int r){
    return rand() % (r - l + 1) + l;
}

int GetScore(){
    int sum = 0;
    rep(i, n){
        rep(j, n) sum += abs(a[i][j] - b[i][j]);
    }
    return 200000000 - sum;
}

void change(int t, int x, int y, int h){
    rep(i, n){
        rep(j, n){
            b[i][j] -= max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
        }
    }

    X[t] = x;
    Y[t] = y;
    H[t] = h;

    rep(i, n){
        rep(j, n){
            b[i][j] += max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
        }
    }
}

void calc_hill_climb(){
    int TimeLimit = 5.95 * CLOCKS_PER_SEC;
    int nowScore = GetScore();
    int time = clock();

    while(clock() - time < TimeLimit){
        int t = RandInt(1, q);
        int pre_x = X[t], new_x = X[t] + RandInt(-9, 9);
        int pre_y = Y[t], new_y = Y[t] + RandInt(-9, 9);
        int pre_h = H[t], new_h = H[t] + RandInt(-19, 19);
        if(new_x < 0 || new_x >= n) continue;
        if(new_y < 0 || new_y >= n) continue;
        if(new_h <= 0 || new_h > n) continue;

        change(t, new_x, new_y, new_h);
        int NewScore = GetScore();

        if(nowScore < NewScore) nowScore = NewScore;
        else change(t, pre_x, pre_y, pre_h);
    }

}

int main(){
    rep(i, n) rep(j, n) cin >> a[i][j];

    rep(i, q){
        X[i] = rand()%n;
        Y[i] = rand()%n;
        H[i] = 1;
        b[Y[i]][X[i]]++;
    }

    calc_hill_climb();

    cout << q << endl;
    rep(i, q){
        cout << X[i] << ' ' << Y[i] << ' ' << H[i] << endl;
    }
}