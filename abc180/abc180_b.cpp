#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    vector<long long> x(n);
    rep(i, n) cin >> x[i];

    long long m = 0, t = -1;
    double y = 0;
    rep(i, n){
        m += abs(x[i]);
        y += x[i] * x[i];
        t = max(t, abs(x[i]));
    }
    cout << m << endl;
    cout << fixed << setprecision(15) << sqrt(y) << endl;
    cout << t << endl;

}
