#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

// 直方体の共通部分の体積が正かどうかを判定する関数
bool hasPositiveIntersection(int a, int b, int c, int d, int e, int f, 
                             int g, int h, int i, int j, int k, int l) {
    // 各軸の最小値と最大値を決定
    int x1_min = min(a, d), x1_max = max(a, d);
    int y1_min = min(b, e), y1_max = max(b, e);
    int z1_min = min(c, f), z1_max = max(c, f);

    int x2_min = min(g, j), x2_max = max(g, j);
    int y2_min = min(h, k), y2_max = max(h, k);
    int z2_min = min(i, l), z2_max = max(i, l);

    // 共通部分の範囲を計算
    int x_overlap_min = max(x1_min, x2_min);
    int x_overlap_max = min(x1_max, x2_max);

    int y_overlap_min = max(y1_min, y2_min);
    int y_overlap_max = min(y1_max, y2_max);

    int z_overlap_min = max(z1_min, z2_min);
    int z_overlap_max = min(z1_max, z2_max);

    // 各軸方向の範囲が重なるかを確認
    bool x_overlap = x_overlap_max > x_overlap_min;
    bool y_overlap = y_overlap_max > y_overlap_min;
    bool z_overlap = z_overlap_max > z_overlap_min;

    // すべての軸で範囲が重なっている場合、共通部分の体積は正
    return x_overlap && y_overlap && z_overlap;
}

int main() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    if (hasPositiveIntersection(a, b, c, d, e, f, g, h, i, j, k, l)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}