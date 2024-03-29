#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<long long> x(n), y(n);
    for(auto &nx : a){
    cin >> nx;
    nx--;
  }
    rep(i, n) cin >> x[i] >> y[i];

    long long res = 0;
    rep(i, n){
        long long cres = 8e18;
        for(auto &nx : a){
            cres = min(cres, (x[i] - x[nx])*(x[i] - x[nx]) + (y[i] - y[nx])*(y[i] - y[nx]));
        }
        res = max(res,cres);
    }
    cout << fixed << setprecision(15) << sqrt((double)res) << endl;
}