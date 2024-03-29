#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> c(n), d(m);
    vector<int> p(m+1);
    rep(i, n) cin >> c[i];
    rep(i, m) cin >> d[i];
    rep(i, m+1) cin >> p[i];

    int sum = 0, eaten = 0;
    rep(i, n){
        string tmp = c[i];
        bool act = false;
        rep(j, m){
            if(tmp == d[j]){
                sum += p[j+1];
                act = true;
            }
        }
        if(act == false){
            sum += p[0];
        }
    }
    cout << sum << endl;


}