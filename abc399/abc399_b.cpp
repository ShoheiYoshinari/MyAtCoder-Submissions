#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    int N;
    cin >> N;
    
    vector<int> P(N);
    vector<pair<int, int>> scores;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        scores.push_back({P[i], i});
    }
    
    sort(scores.rbegin(), scores.rend());
    
    vector<int> rank(N);
    int r = 1;
    
    for (int i = 0; i < N; i++) {
        int score = scores[i].first;
        int count = 1;
        
        while (i + count < N && scores[i + count].first == score) {
            count++;
        }
        
        for (int j = i; j < i + count; j++) {
            rank[scores[j].second] = r;
        }
        
        r += count;
        i += count - 1;
    }
    
    for (int i = 0; i < N; i++) {
        cout << rank[i] << endl;
    }
    
    return 0;
}