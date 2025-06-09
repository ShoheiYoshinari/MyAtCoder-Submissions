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

struct Color {
    double c, m, y;
    Color(double c = 0, double m = 0, double y = 0) : c(c), m(m), y(y) {}
    Color operator+(const Color& other) const {
        return Color(c + other.c, m + other.m, y + other.y);
    }
    Color operator*(double scale) const {
        return Color(c * scale, m * scale, y * scale);
    }
    double distance(const Color& other) const {
        double dc = c - other.c;
        double dm = m - other.m;
        double dy = y - other.y;
        return sqrt(dc*dc + dm*dm + dy*dy);
    }
};

struct Well {
    Color color;
    double amount;
    vector<pair<int,int>> cells;
    
    Well() : amount(0) {}
    
    void addPaint(const Color& newColor, double newAmount) {
        if (amount == 0) {
            color = newColor;
            amount = newAmount;
        } else {
            double totalAmount = amount + newAmount;
            color = Color(
                (color.c * amount + newColor.c * newAmount) / totalAmount,
                (color.m * amount + newColor.m * newAmount) / totalAmount,
                (color.y * amount + newColor.y * newAmount) / totalAmount
            );
            amount = totalAmount;
        }
    }
    
    bool canExtract() const {
        return amount >= 1.0 - 1e-6;
    }
    
    Color extract() {
        if (amount >= 1.0) {
            amount -= 1.0;
            return color;
        } else {
            Color result = color;
            amount = 0;
            return result;
        }
    }
};

int main() {
    int N, K, H, T, D;
    cin >> N >> K >> H >> T >> D;
    
    vector<Color> tubes(K);
    rep(i, K) {
        cin >> tubes[i].c >> tubes[i].m >> tubes[i].y;
    }
    
    vector<Color> targets(H);
    rep(i, H) {
        cin >> targets[i].c >> targets[i].m >> targets[i].y;
    }
    
    vector<vector<int>> vPartitions(N, vector<int>(N-1, 1));
    vector<vector<int>> hPartitions(N-1, vector<int>(N, 1));
    
    rep(i, N) {
        rep(j, N-1) {
            cout << vPartitions[i][j];
            if (j < N-2) cout << " ";
        }
        cout << endl;
    }
    rep(i, N-1) {
        rep(j, N) {
            cout << hPartitions[i][j];
            if (j < N-1) cout << " ";
        }
        cout << endl;
    }
    
    vector<string> operations;
    rep(id, H) {
        Color target = targets[id];
        
        int bestTube = 0;
        double bestDistance = target.distance(tubes[0]);
        
        rep(i, K) {
            double dist = target.distance(tubes[i]);
            if (dist < bestDistance) {
                bestDistance = dist;
                bestTube = i;
            }
        }
        
        int cellRow = 0;
        int cellCol = id % N;
        
        operations.push_back("1 " + to_string(cellRow) + " " + to_string(cellCol) + " " + to_string(bestTube));
        operations.push_back("2 " + to_string(cellRow) + " " + to_string(cellCol));
    }
    
    // Output operations
    for (const string& op : operations) {
        cout << op << endl;
    }
    
    return 0;
}