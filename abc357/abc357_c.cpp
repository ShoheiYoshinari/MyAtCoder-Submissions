#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

vector<string> carpet(int level) {
    if (level == 0) {
        return {"#"};
    }

    //saiki
    vector<string> sub_carpet = carpet(level - 1);

    int size = sub_carpet.size();
    vector<string> carpet(size * 3);
    rep(i, 3){
        rep(j, size){
            if (i == 1) {
                carpet[i * size + j] = sub_carpet[j] + string(size, '.') + sub_carpet[j];
            } else {
                carpet[i * size + j] = sub_carpet[j] + sub_carpet[j] + sub_carpet[j];
            }
        }
    }
    return carpet;
}

int main() {
    int n;
    cin >> n;

    vector<string> carpets = carpet(n);
    for (auto row : carpets) {
        cout << row << endl;
    }

    return 0;
}
