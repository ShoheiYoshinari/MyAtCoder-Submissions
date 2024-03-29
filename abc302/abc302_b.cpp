#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int n, m, x, y;
  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
  string str;

  cin >> n >> m;
  vector<string> S(n);
  for (auto &s : S)
    cin >> s;

  rep(i, n){
    rep(j ,m){
      rep(k, 8) {
        str = "";
        rep(t, 5){
          x = i + dx[k] * t;
          y = j + dy[k] * t;
          if ((x < 0 || x >= n) || (y < 0 || y >= m))
            break;
          str += S[x][y];
        }
        if (str == "snuke") {
          rep(t, 5){
            x = i + dx[k] * t + 1;
            y = j + dy[k] * t + 1;
            cout << x << " " << y << endl;
          }
          return 0;
        }
      }
    }
  }

  return 0;
}