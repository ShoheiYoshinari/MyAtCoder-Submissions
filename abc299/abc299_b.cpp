#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> c(n), r(n);
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> r[i];

    int ans_a = -1, ans_b = -1;
    bool d = false;
    rep(i, n){
        if(c[i] == t){
            d = true;
            if(ans_a < r[i]) {
                ans_a = r[i];
                ans_b = i;
            }
        }
    }
    if(d == false) t = c[0];
    rep(i, n){
        if(c[i] == t){
            d = true;
            if(ans_a < r[i]) {
                ans_a = r[i];
                ans_b = i;
            }
        }
    }

    cout << ans_b + 1 << endl;
}