#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
int n,m;
int x,y;

int a_port(int now){
    rep(i, n){
        if(a[i] - now >= 0) return a[i] + x;
    }
    return -1;
}

int b_port(int now){
    rep(i, m){
        if(b[i] - now >= 0) return b[i] + y;
    }
    return -1;
}


int main() {
    cin >> n >> m >> x >> y;
    vector<int> a(n),b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    int now = 0;
    int cnt = 0;
    while(true){
        auto next = lower_bound(a.begin(),a.end(),now);
        if(next == 0) break;
        now = a[next] + x;
        auto next = lower_bound(b.begin(),b.end(),now);
        if(next == 0) break;
        now = b[next] + y;
        cnt++;   
    }

    cout << cnt << endl;
    return 0;


}
*/

int main() {
    int N,M,X,Y;
    cin >> N >> M;
    cin >> X >> Y;
    vector<int> airportA(N);
    vector<int> airportB(M);
    rep(i, N) cin >> airportA[i];
    rep(i, M) cin >> airportB[i];

  int res = 0;
  int current = 0;
  bool turn = true;
  vector<int>::iterator it;
  it = lower_bound(airportB.begin(), airportB.end(), airportA[0] + X);
  while(it != airportB.end() && it != airportA.end()) {
      current = *it;
      if(turn) {
          it = lower_bound(airportA.begin(), airportA.end(), current + Y);
          res++;
      } else {
          it = lower_bound(airportB.begin(), airportB.end(), current + X);
      }
      turn = !turn;
  }

  cout << res << endl;
  return 0;
}
