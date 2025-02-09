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

struct State {
    int score;
    int x[29];
    char LastMove;
    int LastPos;
};

const int width = 10000;
const int n = 20;

int t;
int p[109], q[109], r[109];
char ans[109];
int NumState[109];
State Beam[109][width];



void beam_search(){
    NumState[0] = 1;
    Beam[0][0].score = 0;
    for(int i = 1; i <= n; i++) Beam[0][0].x[i] = 0;

    for(int i = 1; i <= t; i++){
        vector<State> candi;
        for(int j = 0; j < NumState[i-1]; j++){
            State SousaA = Beam[i-1][j];
            SousaA.LastMove = 'A';
            SousaA.LastPos = j;
            SousaA.x[p[i]]++;
            SousaA.x[q[i]]++;
            SousaA.x[r[i]]++;
            for(int k = 1; k <= n; k++){
                if(SousaA.x[k] == 0) SousaA.score++;
            }

            State SousaB = Beam[i-1][j];
            SousaB.LastMove = 'B';
            SousaB.LastPos = j;
            SousaB.x[p[i]]--;
            SousaB.x[q[i]]--;
            SousaB.x[r[i]]--;
            for(int k = 1; k <= n; k++){
                if(SousaB.x[k] == 0) SousaB.score++;
            }

            candi.push_back(SousaA);
            candi.push_back(SousaB);
        }

        sort(candi.begin(), candi.end(), [](State& a, State& b){
            return a.score > b.score;
        });
        NumState[i] = min(width, (int)candi.size());
        for(int j = 0; j < NumState[i]; j++) Beam[i][j] = candi[j];
    }
    return ;
}


int main(){
    cin >> t;
    for(int i = 1; i <= t; i++) cin >> p[i] >> q[i] >> r[i];

    beam_search();

    int nowPlace = 0;
    for(int i = t; i >= 1; i--){
        ans[i] = Beam[i][nowPlace].LastMove;
        nowPlace = Beam[i][nowPlace].LastPos;
    }

    for(int i = 1; i <= t; i++) cout << ans[i] << endl;
    return 0;

}